# Makefile

EXECUTAVEL = bib
CC = g++
CFLAGS = -c


all:	$(EXECUTAVEL)


bib: main.o Obra.o Biblioteca.o Dijkstra.o
	$(CC) main.o Obra.o Biblioteca.o Dijkstra.o -o $(EXECUTAVEL)


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


Obra.o: Obra.cpp
	$(CC) $(CFLAGS) Obra.cpp


Biblioteca.o: Biblioteca.cpp
	$(CC) $(CFLAGS) Biblioteca.cpp


Dijkstra.o: Dijkstra.cpp
	$(CC) $(CFLAGS) Dijkstra.cpp

run:	$(EXECUTAVEL)
	@./$(EXECUTAVEL)


clean:
	@rm -f ref main.o Obra.o Biblioteca.o Dijkstra.o $(EXECUTAVEL)
