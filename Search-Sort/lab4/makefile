
PP = g++
CFLAGS = -g -Werror -std=c++11 -m64

all: BST QS LS

BST:

	$(PP) $(CFLAGS) -o BST.o BST.cpp
	./BST.o > BST.txt

QS:

	$(PP) $(CFLAGS) -o QuickSort.o QuickSort.cpp
	./QuickSort.o > QuickSort.txt

LS:

	$(PP) $(CFLAGS) -o LinearSort.o LinearSort.cpp
	./LinearSort.o > LinearSort.txt

clean:

	rm BST.o QuickSort.o LinearSort.o
	rm BST.txt QuickSort.txt LinearSort.txt

