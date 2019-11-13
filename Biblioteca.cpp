#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "Obra.cpp"

using namespace std;

class Biblioteca {

	private:
		vector<Obra> obras;
		vector<string> autores; // Mais tarde irei fazer o método que mostra todos os autores
					// da Biblioteca, por isso criei esse vector para guardá-los
	public:
		Biblioteca() {}

		void iniciar() { // Esse método faz, basicamente, o que a main original fazia (menu, seleções, entrada de texto, etc.)

			char choice = ' ';

			while (choice != 'N') {
				cout << "Deseja adicionar alguma obra? Digite 'S' para sim ou 'N' para não:" << endl;
				cin >> choice;
				cin.get();
				if (choice == 'S') {
					cout << "Digite o nome do arquivo no formato .enw:" << endl;
					string n;
					getline(cin, n);
					adicionaObra(n); // Método implementado abaixo
				}

				else if (choice != 'S' && choice != 'N') cout << "Digite uma opção válida!" << endl;

				cout << "\n";
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
				cout << "\n";

				if (op == 1) {
					cout << obtemTitulos(); // Método implementado abaixo
				}


	        /*	if (op == 2) { // AINDA TENHO QUE PENSAR EM COMO FAZER (MOSTRAR TODOS OS AUTORES SEM REPETIÇÃO)
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
					cout << obtemObras(); // Método implementado abaixo
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
					cout << "\n";

					if (op2 == 1) { // Parte do Ícaro (filtrar autor por partes do nome)
						string nom;
						cout << "Digite o nome do autor a ser buscado na base de dados:" << endl;
						getline(cin, nom);
						cout << "\n";
						searchAutor(obras, nom); // Método criado pelo Ícaro
					}


					if (op2 == 2) { // Parte do Ícaro (filtrar títulos por palavras soltas)
						string nom;
						cout << "Digite parte do título a ser buscado na base de dados:" << endl;
						getline(cin, nom);
						cout << "\n";
						searchTitulo(obras, nom); // Método criado pelo Ícaro
					}

				}

				cout << "\n";

			}
		}


		void adicionaObra(string nome) { // Cria uma obra nova e a adiciona na lista de obras
			Obra nova(nome);
			obras.push_back(nova);
		}

		string obtemTitulos() { // Passa para um stringstream todos os títulos das obras que estão na lista de obras
			stringstream ss;
			ss << "Obras cadastradas:" << endl;
			for (int i = 0; i < obras.size(); i++) {
				ss << obras[i].obtemTitulo() << endl;
			}
			return ss.str();
		}

		string obtemObras() { // Passa para um stringstream todos os dados das obras que estão na lista de obras
			stringstream ss;
			for (int i = 0; i < obras.size(); i++) {
				ss << obras[i].obtemObra() << endl;
			}
			return ss.str();
		}

		// MÉTODOS FEITOS PELO ÍCARO ABAIXO E COM OS COMENTÁRIOS DO PRÓPRIO //

		void searchTitulo(vector<Obra> obras, string str1) { //busca em toda a base de dados por parte do título da obra, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
		// busca por titulo, obra a obra
			int f = 0;//flag
			for (int j = 0; j < obras.size(); j++) {
				string str = obras[j].obtemTitulo(); //a string onde será buscada
				size_t achou = str.find(str1);// "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
				if (achou != string::npos) {// npos= no position, ou seja, se o resultado não for "no position" é pq achou
					f++;//o termo pesquisado foi encontrado pelo menos uma vez
					cout << "O termo "
						<< str1
						<< " ocorre na obra: " << obras[j].obtemTitulo() << endl;
				}

			}

			if(f == 0) cout << "O termo " << str1 << " não foi encontrado na base de dados." << endl;
		}

		void searchAutor(vector<Obra> obras, string str1) {//busca em toda a base de dados por parte do nome do autor, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
		// busca por autor, obra a obra
			int f = 0;//flag
			for (int j = 0; j < obras.size(); j++) {
				for (int k = 0; k < obras[j].obtemNumAutor(); k++) {//buscar em cada um dos autores 
					string str = obras[j].obtemAutor(k); //a string onde será buscada
					size_t achou = str.find(str1);// "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
					if (achou != string::npos) {// npos= no position, ou seja, se o resultado não for "no position" é pq achou
						f++;//o termo pesquisado foi encontrado pelo menos uma vez
						cout << "O autor "
							<< str1
							<< " aparece na obra: " << obras[j].obtemTitulo() << endl;
							break;//achou já, não vai ter outro com o mesmo nome
					}

				}

			}

			if(f == 0) cout << "O nome " << str1 << " não foi encontrado na base de dados." << endl;
		}
	};
