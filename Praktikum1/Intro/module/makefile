# ---------------------------------------------------------------------------
# Makefile fuer Programmbeispiel mit searaten Dateien
# Fach:	BS, J. Zeman, Sept. 99
#       update M. Thaler, Jan. 11
# File: makefile 
# ---------------------------------------------------------------------------
#macros

CC = gcc
CFLAGS = -Wall -g

main:		main.o func1.o func2.o func3.o
		$(CC) $(CFLAGS) main.o func1.o func2.o func3.o -o main

main.o:		main.c mydefs.h func1.h func2.h func3.h
		$(CC) $(CFLAGS) -c main.c -o main.o

func1.o:	func1.c mydefs.h func1.h
		$(CC) $(CFLAGS) -c func1.c -o func1.o

func2.o:	func2.c mydefs.h func2.h
		$(CC) $(CFLAGS) -c func2.c -o func2.o

func3.o:	func3.c mydefs.h func3.h
		$(CC) $(CFLAGS) -c func3.c -o func3.o

clean:		
		rm -f main
		rm -f *.o
		@echo "directory cleaned"

all:
		@rm -f  *.o
		make main
#-----------------------------------------------------------------------------
