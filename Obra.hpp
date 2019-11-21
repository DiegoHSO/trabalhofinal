//Obra.hpp (Diego Henrique, Icaro Stumpf, Samuel Nascimento; 21 nov. 2019)

#ifndef _OBRAHPP_
#define _OBRAHPP_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Obra {

	private:
		vector<string> autores;
		string titulo;
		int ano;
		int numAutores; // para facilitar a busca por autores

	public:
		Obra(string nome);

		Obra();

		void defineAutor(string autor);

		void defineAno(int ano);

		void defineTitulo(string titulo);

		string obtemAutor(int n);

		int obtemNumAutor();

		string obtemTitulo();

		int obtemAno();

		string obtemObra();

		vector<string> obtemAutores();

};

#endif
