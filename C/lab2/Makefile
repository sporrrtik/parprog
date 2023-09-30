fw_lab2:
		gcc -m64 -c -IFW_1.0_Lin64 lab1.c -lm
		gcc -m64 -LFW_1.0_Lin64/lib lab1.o -lfwBase -lfwSignal -lm
		chmod 777 ./*

gcc-seq:
		gcc -O3 -Wall -Werror -m64 -c -IFW_1.0_Lin64 lab1.c -lm
		gcc -m64 -LFW_1.0_Lin64/lib lab1.o -lfwBase -lfwSignal -lm
		chmod 777 ./*

start-gcc:
		./a.out 1 10 1 one
		./a.out 1 10 2 two
		./a.out 1 10 4 four
		./a.out 1 10 6 six
		./a.out 6 10 1 one
		./a.out 6 10 2 two
		./a.out 6 10 4 four
		./a.out 6 10 6 six
		./a.out 7 10 1 one
		./a.out 7 10 2 two
		./a.out 7 10 4 four
		./a.out 7 10 6 six
	        ./a.out 10 10 1 one
		./a.out 10 10 2 two
		./a.out 10 10 4 four
		./a.out 10 10 6 six
		./a.out 11 10 1 one
		./a.out 11 10 2 two
		./a.out 11 10 4 four
		./a.out 11 10 6 six
		./a.out 54 10 1 one
		./a.out 54 10 2 two
		./a.out 54 10 4 four
		./a.out 54 10 6 six
		./a.out 55 10 1 one
		./a.out 55 10 2 two
		./a.out 55 10 4 four
		./a.out 55 10 6 six
		chmod 777 ./*
                
test:
		./a.out 10 10 1

clean:
		rm -f lab1.o
		rm -f a.out
		
