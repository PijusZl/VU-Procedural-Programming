.PHONY: testing, compileTest

compile: main.c source.c
	gcc -o main main.c source.c
	
run:
	main

compileTest: test.c source.c
	gcc -o test test.c source.c

test:
	test