#include "lab1.h"
#include <omp.h>

#define N_THREADS 10
#define SCHEDULE_TYPE static
#define SCHEDULE_CHUNK_SIZE 10

int main(int args, char *argv[]) {
    int i, N1, N2, A;
    struct timeval T1, T2;
    long delta_ms;
    N1 = atoi(argv[1]);
    N2 = N1 / 2;
    A = atoi(argv[2]);
    FILE *S1, *S2;
    const char *first = "_ans.txt";
    const char *second = "_delt.txt";
    char *filename = argv[3];
    char ans[512], delt[512];
    snprintf(ans, sizeof ans, "%s%s", filename, first);
    snprintf(delt, sizeof delt, "%s%s", filename, second);
    S1 = fopen(ans, "a");
    S2 = fopen(delt, "a");

    if (N1 == 0 || A == 0) {
        return -1;
    }
    gettimeofday(&T1, NULL);

    double* M1 = malloc(sizeof(double )*N1);
    double* M2 = malloc(sizeof(double )*N2);
    for (i = 0; i < 100; i++) {
        unsigned int seed = i;
        generate_array(N1, M1, 1, A, seed);

        do_some_with_all_array_elem(N1, M1, exp_square_sqrt);

        generate_array(N2, M2, A, 10 * A, seed);
    
        preparing_M2(N2, M2, fabs_tan);

        merge(N1, M1, N2, M2, min);
        
        insertion_sort(N2, M2);

        double result = reduce(N2, M2);
        fprintf(S1, "%d %f\n", i, result);
    }
    
    free(M1);
    free(M2);

    gettimeofday(&T2, NULL);
    delta_ms = 1000000*(T2.tv_sec-T1.tv_sec)+T2.tv_usec-T1.tv_usec;
    printf("\nN=%d. Milliseconds passed: %ld\n", N1, delta_ms);
    fprintf(S2, "%d %ld\n", N1, delta_ms);
    fclose(S1);
    fclose(S2);
    return 0;
}

double reduce(int n, double array[]) {
    double sum_sin_even = 0;
    int min_not_zero_index = find_min_not_zero(n, array);
    if (min_not_zero_index == -1) {
        return NAN;
    }
    
    int j;
#pragma omp parallel for default(none) private(j) shared(n, min_not_zero_index, array) reduction(+:sum_sin_even) num_threads(N_THREADS) schedule(SCHEDULE_TYPE,SCHEDULE_CHUNK_SIZE)
    for (j = 0; j < n; j++) {
        double div_to_min = array[j] / array[min_not_zero_index];
        if ((int) floor(div_to_min) % 2 == 0) {
            sum_sin_even = sum_sin_even + sin(array[j]);
        }
    }
    return sum_sin_even;
}

void merge(int array_len, double array[], int merge_array_len, double merge_array[], double (*merge_func)(double, double)) {
    int len = min(array_len, merge_array_len);
    int j;
#pragma omp parallel for default(none) private(j) shared(array, merge_array, len, merge_func) num_threads(N_THREADS) schedule(SCHEDULE_TYPE,SCHEDULE_CHUNK_SIZE)
    for (j = 0; j < len; j++) {
        merge_array[j] = merge_func(array[j], merge_array[j]);
    }
}

void preparing_M2(int n, double array[], double (*func)(double)) {
    double* tmp_array = malloc(sizeof(double )*n);
    copy_array(array,tmp_array,n);
    int j;
#pragma omp parallel for default(none) private(j) shared(array, tmp_array, n, func) num_threads(N_THREADS) schedule(SCHEDULE_TYPE,SCHEDULE_CHUNK_SIZE)
    for (j = n - 1; j >= 0; j--) {
        if (j != 0) {
            array[j] =tmp_array[j - 1] + tmp_array[j];
        }
        array[j] = func(array[j]);
    }
    free(tmp_array);
}

void copy_array(double from_array[], double to_array[], int len) {
    int i;
#pragma omp parallel for default(none) private(i) shared(from_array, to_array, len) num_threads(N_THREADS) schedule(SCHEDULE_TYPE,SCHEDULE_CHUNK_SIZE)
    for(i = 0; i < len;i++){
        to_array[i] = from_array[i];
    }
}

void do_some_with_all_array_elem(int n, double array[], double (*func)(double)) {
    int j;
#pragma omp parallel for default(none) private(j) shared(n, array, func) num_threads(N_THREADS) schedule(SCHEDULE_TYPE,SCHEDULE_CHUNK_SIZE)
    for (j = 0; j < n; j++) {
        array[j] = func(array[j]);
    }
}

int find_min_not_zero(int n, double sorted_array[]) {
    for (int i = 0; i < n; i++) {
        if (sorted_array[i] != 0) {
            return i;
        }
    }
    return -1;
}

void generate_array(int n, double array[], int minValue, int maxValue, unsigned int seed) {
    for (int j = 0; j < n; j++) {
        array[j] = minValue + rand_r(&seed) % maxValue;
    }
}

void insertion_sort(int n, double array[]) {
    double new_elem;
    int location;
    for (int i = 1; i < n; i++) {
        new_elem = array[i];
        location = i - 1;
        while (location >= 0 && array[location] > new_elem) {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = new_elem;
    }
}
