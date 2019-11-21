// Biblioteca.hpp (Diego Henrique, Ícaro Stumpf, Samuel Nascimento, 21 nov. 2019)

#ifndef _BIBLIOTECAHPP_
#define _BIBLIOTECAHPP_


#include<iostream>
#include<string>
#include<vector>
#include "Obra.hpp"
#include "Grafo.hpp"
using namespace std;

class Biblioteca {

	private:
		vector<Obra> obras;
		vector<string> autores;
		Grafo grafo;

	public:
		Biblioteca();

		void iniciar();

		void adicionaObraArquivo(string nome);

		void adicionaObraTeclado();

		string obtemTitulos();

		string obtemAutores();

		string obtemObras();

		void searchTitulo(string titulo);

		void searchAutor(string autor);

		void searchObras(int a1, int a2);

		int porAno(int ano);

		int porAutor(string autor);

		void toGraph();

		void visualizaDistancias(string nome);

		void toGraphviz(string arquivo);
};

#endif
