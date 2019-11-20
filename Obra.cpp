#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

class Obra {

	private:
		vector<string> autores;
		string titulo;
		int ano;
		int numAutores; // para facilitar a busca por autores

	public:
		Obra(string nome) {
			numAutores = 0;
			ano = 0;

			ifstream arq;
			arq.open(nome, ios::in);
			if (!arq.is_open()) {
				cout << "Arquivo inválido!" << endl;
				arq.close();
				return;
			}

			string linha;
			string id;

			while (arq.good()) {
				arq >> id;
				//cout << "ID vale:" << id << endl;

				if (id == "%A") {
					arq.get(); // Pega o espaço que vem depois do %A
					string nome; // String temporária para armazenar o nome
					string sobrenome; // String temporária para armazenar o sobrenome

					char delim = ','; // Delimitador criado para separar o nome do sobrenome
					getline(arq, sobrenome, delim); // Sobrenome sendo pego do arquivo
					arq.get(); // Pega o espaço que vem depois da vírgula, no arquivo

					getline(arq, nome); // Nome sendo pego no arquivo
					nome.erase(nome.end() - 1); // Eliminando a quebra de linha que vem após o nome

					string autor = nome + " " + sobrenome; // Concatena nome e sobrenome em uma única string
					autores.push_back(autor); // Adicona o autor no vector de Autores
				}

				if (id == "%T") {
					arq.get(); // Pega o espaço que vem depois do %T
					getline(arq, titulo); // Coloca o título da obra na variável titulo
				}

				if (id == "%D") {
					arq.get(); // Pega o espaço que vem depois do %T
					arq >> ano; // Coloca o ano da obra na variável ano
				}

			}
			this->numAutores=autores.size(); // Salva na variável numAutores o número de autores salvos no vector
			arq.close();

		}

		Obra() {
			numAutores = 0;
			ano = 0;
		}

		void defineAutor(string autor) {
			this->autores.push_back(autor);
			this->numAutores = autores.size();
		}

		void defineAno(int ano) {
			this->ano = ano;
		}

		void defineTitulo(string titulo) {
			this->titulo = titulo;
		}

		string obtemAutor(int n) {//criei para poder fazer a pesquisa por autor
			return autores[n];
		}

		int obtemNumAutor() {//criei para facilitar a pesquisa por autor
			return numAutores;
		}

		string obtemTitulo() {
			return titulo;
		}

		int obtemAno() { // adicionei para poder fazer outro método na Biblioteca.cpp  / Samuel
			return ano;
		}

		string obtemObra() {
			stringstream ss;
			ss << "Título: " << titulo << endl;
			ss << "Ano de lançamento: " << ano << endl;
			ss << "Autor(es): ";
			for (int i = 0; i < numAutores; i++) {
				if (i == numAutores - 1) ss << autores[i] << endl;
				else ss << autores[i] << ", ";
			}
			return ss.str();
		}

		vector<string> obtemAutores() {
			return autores;
		}

};
