# Makefile for my Stack Project
# Dylan Brown

stackOfStrings: stackOfStrings.o stack.o
	gcc -o stackOfStrings stackOfStrings.o stack.o

stackOfStrings.o: stackOfStrings.c stack.h
	gcc -c -Wall stackOfStrings.c

stack.o: stack.c stack.h
	gcc -c -Wall stack.c
