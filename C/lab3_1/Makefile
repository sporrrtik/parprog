all: lab1


lab1:
		gcc lab1.c -o lab1 -lm

omp:
		gcc -O3 -Wall -Werror lab1.c -fopenmp -o lab3_omp -lm
		
omp_test:
		./lab3_omp 100 10 test_omp
		
omp_clean:
		rm -f lab3_omp
		rm -f test_omp_ans.txt

gcc-seq:
		gcc -O3 -Wall -Werror lab1.c -fopenmp -o lab1-par-1 -lm
		gcc -O3 -Wall -Werror lab1.c -fopenmp -o lab1-par-2 -lm
		gcc -O3 -Wall -Werror lab1.c -fopenmp -o lab1-par-4 -lm
		gcc -O3 -Wall -Werror lab1.c -fopenmp -o lab1-par-10 -lm

start-gcc:
		./lab1-par-1 10000 10 par1
		./lab1-par-2 10000 10 par2
		./lab1-par-4 10000 10 par4
		./lab1-par-6 10000 10 par6

clean:
		rm -f lab1
		rm -f lab1-par-1
		rm -f lab1-par-2
		rm -f lab1-par-4
		rm -f lab1-par-6
		rm -f lab1-seq
		rm -f lab1-tcc-4
		rm -f lab1-pcc-4
