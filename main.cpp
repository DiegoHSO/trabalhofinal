#include<iostream>
#include<vector>
#include<string>
#include "Obra.cpp"

using namespace std;

int main() {

	vector<Obra> obras;

	char choice = ' ';

	while (choice != 'N') {
		cout << "Deseja adicionar alguma obra? Digite 'S' para sim ou 'N' para não:" << endl;
		cin >> choice;
		cin.get();
		if (choice == 'S') {
			cout << "Digite o nome do arquivo no formato .enw:" << endl;
			string n;
			getline(cin, n);
			Obra nova(n);
			obras.push_back(nova);
		}

		else if (choice != 'S' && choice != 'N') cout << "Digite uma opção válida!" << endl;
	}

	int op;
	while (op != 5) {

		cout << "(1) Ver todas as obras cadastradas" << endl;
		cout << "(2) Ver todos os autores cadastrados" << endl;
		cout << "(3) Ver todas as obras e seus respectivos dados (autor(es), ano de lançamento, título)" << endl;
		cout << "(4) Filtrar as obras por critérios específicos" << endl;
		cout << "(5) Sair do programa" << endl;

		cin >> op;
		cin.get();

		if (op == 1) {
			int j = 0;
			for (auto i = obras.begin(); i != obras.end(); i++) {
				cout << obras[j].obtemTitulo() << endl;
				j++;
			}
		}

	/*	if (op == 2) { // AINDA TENHO QUE PENSAR EM COMO FAZER 
			int k = 0;
			for (auto i = obras.begin(); i != obras.end(); i++) {
				int l = 0;
				for (auto j = obras.begin() + 1; j != obras.end(); j++) {
					if (obras[k].obtem
					cout << obras[k].obtemAutor() << endl;
					j++;
			}
		}
	*/
		if (op == 3) {
			int j = 0;
			for (auto i = obras.begin(); i != obras.end(); i++) {
				cout << obras[j].obtemObra() << endl;
				j++;
			}
		}


		if (op == 4) {

			cout << "Deseja filtrar as obras por:" << endl;
			cout << "(1) Autor" << endl;
			cout << "(2) Título" << endl;
			cout << "(3) Intervalos entre 2 anos" << endl;
			cout << "(4) Voltar ao menu anterior" << endl;

			int op2;
			cin >> op2;
			cin.get();

			/* if (op2 == 1) { // FAZER - ICARO
				string nom;
				cout << "Digite o nome:" << endl;
				getline(cin, nom);

				int j = 0;
				for (auto i = obras.begin(); i != obras.end(); i++) { 
					if (obras[j].procuraAutor(nom)) cout << obras[j].obtemTitulo() << endl;
					j++;
				}

				cout << "\n" << endl;
			}	*/
		}
	}

	return 0;
}

