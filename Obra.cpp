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
					string autor;
					getline(arq, autor);
					autores.push_back(autor); // Coloca o autor no vetor de Autores
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
			this->numAutores=autores.size(); //vide o privado
			arq.close();

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
			ss << "Título: " << endl << titulo << endl;
			ss << "Ano de lançamento: " << endl << ano << endl;
			ss << "Autor(es): " << endl;
			for (int i = 0; i < numAutores; i++) {
				ss << autores[i] << endl;
			}

			ss << endl;
			return ss.str();
		}


};
