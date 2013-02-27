# ---------------------------------------------------------------------------
# Makefile fuer Programmbeispiel mit searaten Dateien
# Fach:     BS, J. Zeman, Sept. 99
# Changes:  M. Thaler, CFLGS added, 1/2010
# File:     makefile 
# ---------------------------------------------------------------------------
#macros
CC    = gcc -std=gnu99
CFLGS = -g -Wall

doit:
		make --no-print-directory test1
		make --no-print-directory test2

test1:		test1.o mlist.o mthread.o 
		$(CC) $(CFLGS) test1.o mlist.o mthread.o -o $@

test2:		test2.o mlist.o mthread.o 
		$(CC) $(CFLGS) test2.o mlist.o mthread.o -o $@

test3:		test3.o mlist.o mthread.o 
		$(CC) $(CFLGS) test3.o mlist.o mthread.o -o $@

.c.o:		$< mlist.h  mthread.h
		$(CC) $(CFLGS) -c $< -o $*.o

clean:		
		rm -f test1 test2 test3
		rm -f *.o
		@echo "directory cleaned"

all:
		@rm -f *.o
		make --no-print-directory test1
		make --no-print-directory test2
#-----------------------------------------------------------------------------
