SHELL = /bin/sh

OBJS = a.out
CFLAG = -g
CC = c++
INCLUDE = Headers/
MATRIX = src/Matrix/* 
VARIABLE = src/Variable/*.cpp src/Variable/operations/* 
VECTOR = src/Vector/*.cpp src/Vector/operations/*

make: 
	@$(CC) -std=c++11 $(CFLAG) -I $(INCLUDE) $(MATRIX) $(VARIABLE) $(VECTOR) main.cpp -o $(OBJS) && ./$(OBJS)

clean: 
	@rm a.out && rm -r a.out.dSYM