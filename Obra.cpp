#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Obra {

	private:
		vector<string> autores;
		string titulo;
		int ano;

	public:
		Obra(string nome) {

			ifstream arq;
			arq.open(nome, ios::in);
			if (!arq.is_open()) {
				cout << "Arquivo inválido!" << endl;
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

			arq.close();

		}

		void mostrarAutores() {
			for (int i = 0; i < 6; i++) cout << "Autor:" << autores[i] << endl;
		}

		bool procuraAutor(string n) {
			int j = 0;
			for (auto i = autores.begin(); i != autores.end(); i++) {
					if (autores[j].compare(n) == 1) return true;
				//	else cout << autores[j].compare(n) << endl;
					j++;
			}

			return false;

		}

		string obtemTitulo() {
			return titulo;
		}

};
