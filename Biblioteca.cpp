#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include "Obra.cpp"

using namespace std;

class Biblioteca {

	private:
		vector<Obra> obras;
		set<string> autores;

	public:
		Biblioteca() {}

		void iniciar() { // Esse método faz, basicamente, o que a main original fazia (menu, seleções, entrada de texto, etc.)

			char choice = ' ';

			while (choice != 'N') {
				cout << "Deseja adicionar alguma obra? Digite 'S' para sim ou 'N' para não:" << endl;
				cin >> choice;
				cin.get();
				if (choice == 'S') {

					cout << "\nDeseja adicionar via:" << endl;
					cout << "(1) Teclado" << endl;
					cout << "(2) Arquivo" << endl;

					int op;
					cin >> op;
					cin.get();

					if (op == 1) {
						adicionaObraTeclado();
					}

					else if (op == 2) {
						cout << "\nDigite o nome do arquivo no formato .enw:" << endl;
						string n;
						getline(cin, n);
						adicionaObraArquivo(n); // Método implementado abaixo
					}

					else cout << "\nOpção inválida! Voltando ao menu anterior..." << endl;
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

	       			if (op == 2) {
					cout << obtemAutores(); // Método implementado abaixo
				}

				if (op == 3) {
					cout << obtemObras(); // Método implementado abaixo
				}

				if (op == 4) {
					cout << "Deseja filtrar as obras por:" << endl;
					cout << "(1) Autor" << endl;
					cout << "(2) Título" << endl;
					cout << "(3) Intervalos entre 2 anos" << endl;
					cout << "(4) Totalização do número de obras por ano" << endl;
					cout << "(5) Totalização do número de obras por autor" << endl;
					cout << "(6) Voltar ao menu anterior" << endl;

					int op2;
					cin >> op2;
					cin.get();
					cout << "\n";

					if (op2 == 1) { // Parte do Ícaro (filtrar autor por partes do nome)
						string nom;
						cout << "Digite o nome do autor a ser buscado na base de dados:" << endl;
						getline(cin, nom);
						cout << "\n";
						searchAutor(nom); // Método criado pelo Ícaro
					}


					if (op2 == 2) { // Parte do Ícaro (filtrar títulos por palavras soltas)
						string nom;
						cout << "Digite parte do título a ser buscado na base de dados:" << endl;
						getline(cin, nom);
						cout << "\n";
						searchTitulo(nom); // Método criado pelo Ícaro
					}

					if (op2 == 3) { // Pesquisa entre dois anos digitados pelo usuário, implementado por Samuel
						int ano1, ano2;
						cout << "Digite os dois anos para pesquisar os livros neste intervalo:" << endl;
						cin >> ano1;
						cin.get();
						cin >> ano2;
						cin.get();
						cout << "\nPesquisando obras entre " << ano1 << " e " << ano2 << endl << "\n";
						searchObras(ano1, ano2);
					}

					if (op2 == 4) { // Totalização do número de obras por ano - Samuel vai implementar
						cout << "Digite o ano:" << endl;
						int ano;
						cin >> ano;
						int quantidade = porAno(obras, ano);
						cout << "\nQuantidades de obras no ano " << ano << ": " << quantidade << endl;
					}

					if (op2 == 5) { // Totalização do número de obras por autor - Samuel vai implementar
						cout << "Digite o nome do autor:" << endl;
						string autor;
						getline(cin, autor);
						int quantidade = porAutor(obras, autor);
						cout << "\nQuantidade de obras publicadas pelo autor " << autor << ": " << quantidade << endl;
					}


				}

				cout << endl;
			}
		}


		void adicionaObraArquivo(string nome) { // Cria uma obra nova e a adiciona na lista de obras
			Obra nova(nome);

			for (int i = 0; i < nova.obtemNumAutor(); i++)
				autores.insert(nova.obtemAutor(i));

			obras.push_back(nova);
		}

		void adicionaObraTeclado() { // Diego vai implementar
			Obra nova;
			string temp;
			int a;

			cout << "\nDigite o nome da obra:" << endl;
			getline(cin, temp);
			nova.defineTitulo(temp);

			cout << "\nDigite o ano de publicação:" << endl;
			cin >> a;
			cin.get();
			nova.defineAno(a);

			char choice;

			while (choice != 'N') {
				cout << "\nDigite o nome do autor:" << endl;
				getline(cin, temp);
				nova.defineAutor(temp);

				cout << "\nDeseja adicionar outro autor? Digite 'S' para sim ou 'N' para não:" << endl;
				cin >> choice;
				cin.get();

				if (choice != 'N' && choice != 'S') cout << "\nOpção inválida!" << endl;
			}

			for (int i = 0; i < nova.obtemNumAutor(); i++)
				autores.insert(nova.obtemAutor(i));

			obras.push_back(nova);
		}

		string obtemTitulos() { // Passa para um stringstream todos os títulos das obras que estão na lista de obras
			stringstream ss;
			ss << "Obras cadastradas:" << endl;
			for (int i = 0; i < obras.size(); i++)
				ss << obras[i].obtemTitulo() << endl;

			return ss.str();
		}

		string obtemAutores() {
			stringstream ss;
			ss << "Autores cadastrados:" << endl;
			set <string> :: iterator itr;
			for (itr = autores.begin(); itr != autores.end(); ++itr)
				ss << *itr << endl;

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

		void searchTitulo(string str1) { //busca em toda a base de dados por parte do título da obra, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
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

		void searchAutor(string str1) {//busca em toda a base de dados por parte do nome do autor, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
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

		void searchObras(int a1, int a2){
			for(int i = 0; i < obras.size(); i++)
				if(obras[i].obtemAno() >= a1 && obras[i].obtemAno() <= a2)
					cout << obras[i].obtemObra() << endl;

		}
		
		int porAno(vector <Obra> obras, int ano){ // sam
			int qtd = 0;
			for(int i = 0; i < obras.size(); i++){
				if(obras[i].obtemAno() == ano){
					qtd++;
				}
			}
			return qtd;
		}
		
		int porAutor(vector <Obra> obras, string autor){// sam
			int qtd = 0;
			for (int i = 0; i < obras.size(); i++) {
				for (int j = 0; j < obras[j].obtemNumAutor(); j++) {
					string nomeAutor = obras[i].obtemAutor(j);
					size_t achou = nomeAutor.find(autor);
					if (achou != string::npos) {
						qtd++;
					}
				}
			}
			return qtd;
		}
	};
