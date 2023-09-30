#ifndef PARALLEL_PROGRAMMING_LAB1_H
#define PARALLEL_PROGRAMMING_LAB1_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <fwSignal.h>
#include <fwBase.h>


int find_min_not_zero(int n, double sorted_array[]);
void generate_array(int n, double array[], int minValue, int maxValue, unsigned int seed);
//void do_some_with_all_array_elem(int n, double array[], double (*func)(double));
//void preparing_M2(int n, double array[], double (*func)(double));
//void merge(int array_len, double array[], int merge_array_len, double merge_array[], double (*merge_func)(double, double));
double reduce(int n, double array[]);
void insertion_sort(int n, double mass[]);
void copy_array(double from_array[], double to_array[], int len);

void fw_exp_sqrt(int n, double *array);

void fw_preparing_M2(int n, double *array);

void fw_merge(int array_len, double *array, int merge_array_len, double *merge_array);

/*double exp_square_sqrt(double x)
{
    return exp(sqrt(x));
}
double fabs_tan(double x)
{
    return fabs(tan(x));
}*/
double min(double a, double b)
{
    return a >= b ? b : a;
}
#endif // PARALLEL_PROGRAMMING_LAB1_H
