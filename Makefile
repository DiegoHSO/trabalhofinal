#Makefile (Trabalho final de Algoritmos II;Diego Henrique, Ícaro Stumpf, Samuel Nascimento; Novembro de 2019)

CFLAGS=-std=c++11

all:		app

app:		main.o Biblioteca.o Obra.o Grafo.o
		@g++ main.o Biblioteca.o Obra.o Grafo.o -o app

main.o:		main.cpp Biblioteca.hpp Obra.hpp Grafo.hpp 
		@g++ ${CFLAGS} -c main.cpp

Biblioteca.o:	Biblioteca.cpp Biblioteca.hpp
		@g++ ${CFLAGS} -c Biblioteca.cpp

		
Obra.o:		Obra.cpp Obra.hpp
		@g++ ${CFLAGS} -c Obra.cpp

Grafo.o:	Grafo.cpp Grafo.hpp
		@g++ ${CFLAGS} -c Grafo.cpp

run:		app
		@ ./app

clean:
		@rm -f main.o Biblioteca.o Obra.o Grafo.o app

