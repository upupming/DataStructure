
PP = g++
CFLAGS = -g -Werror -std=c++11 -m64

all: Graph ER

Graph:

	$(PP) $(CFLAGS) -o Graph.o Graph.cpp Graph.h
	./Graph.o > Graph.txt

ER:

	$(PP) $(CFLAGS) -o EquipReplace.o EquipReplace.cpp
	./EquipReplace.o > EquipReplace.txt


clean:

	rm Graph.o EquipReplace.o
	rm Graph.txt EquipReplace.txt

