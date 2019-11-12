#include<iostream>
#include<vector>
#include<string>
#include "Obra.cpp"

using namespace std;

int main() {

	vector<Obra> obras;

	char op = ' ';

	while (op != 'N') {
		cout << "Deseja adicionar alguma obra? Digite 'S' para sim ou 'N' para não:" << endl;
		cin >> op;
		cin.get();
		if (op == 'S') {
			cout << "Digite o nome do arquivo no formato .enw:" << endl;
			string n;
			getline(cin, n);
			Obra nova(n);
			obras.push_back(nova);
		}

		else if (op != 'S' && op != 'N') cout << "Digite uma opção válida!" << endl;
	}

	int op2;
	while (op2 != 4) {
		cout << "Deseja filtrar as obras por:" << endl;
		cout << "(1) Autor" << endl;
		cout << "(2) Título" << endl;
		cout << "(3) Intervalos entre 2 anos;" << endl;
		cout << "(4) Não desejo filtrar obras. Quero sair do programa." << endl;

		cin >> op2;
		cin.get();

		if (op2 == 1) {
			string nom;
			cout << "Digite o sobrenome e nome do autor separados por vírgula, respectivamente:" << endl;
			getline(cin, nom);
			int j = 0;
			for (auto i = obras.begin(); i != obras.end(); i++) {
					if (obras[j].procuraAutor(nom)) cout << obras[j].obtemTitulo() << endl;
					j++;
			}

			cout << "\n" << endl;
		}
	}

	return 0;
}

