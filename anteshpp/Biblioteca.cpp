// Biblioteca.cpp (Diego Henrique, Ícaro Stumpf, Samuel Nascimento; 21 nov. 2019)

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Biblioteca.hpp"
#include "Obra.hpp"
#include "Grafo.hpp"

using namespace std;

Biblioteca::Biblioteca() {}

void Biblioteca::iniciar() { // Método que manipula a estrutura

			string choice = ' ';

			while (choice != 'N') {
				cout << "\nDeseja adicionar alguma obra? Digite 'S' para sim ou 'N' para não:" << endl;
				getline(cin, choice);

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
						n = n + ".enw";
						adicionaObraArquivo(n);
					}

					else cout << "\nOpção inválida! Voltando ao menu anterior..." << endl;
				}

				else if (choice != 'S' && choice != 'N') cout << "Digite uma opção válida!" << endl;

			}

			int op;
			while (op != 7) {
				cout << "\n(1) Ver todas as obras cadastradas" << endl;
				cout << "(2) Ver todos os autores cadastrados" << endl;
				cout << "(3) Ver todas as obras e seus respectivos dados (autor(es), ano de lançamento, título)" << endl;
				cout << "(4) Filtrar as obras por critérios específicos" << endl;
				cout << "(5) Visualizar as distâncias colaborativas entre um autor e todos os outros" << endl;
				cout << "(6) Exportar dados de conexões entre autores para o modelo Graphviz" << endl;
				cout << "(7) Sair do programa" << endl;

				cin >> op;
				cin.get();
				cout << "\n";

				if (op == 1) {
					cout << obtemTitulos();
				}

				if (op == 2) {
					cout << obtemAutores();
				}

				if (op == 3) {
					cout << obtemObras();
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
						int quantidade = porAno(ano);
						cout << "\nQuantidades de obras no ano " << ano << ": " << quantidade << endl;
					}

					if (op2 == 5) { // Totalização do número de obras por autor - Samuel vai implementar
						cout << "Digite o nome do autor:" << endl;
						string autor;
						getline(cin, autor);
						int quantidade = porAutor(autor);
						cout << "\nQuantidade de obras publicadas pelo autor " << autor << ": " << quantidade << endl;
					}


				}

				if (op == 5) {
					cout << "Digite o nome do autor:" << endl;
					string tmp;
					getline(cin, tmp);
					visualizaDistancias(tmp);
				}

				if (op == 6) {
					cout << "Digite o nome do arquivo para o qual deseja exportar:" << endl;
					string tmp;
					getline(cin, tmp);
					toGraphviz(tmp);
				}

				else if (op > 7) cerr << "Opção inválida!" << endl;

				cout << endl;
			}
		}


		void Biblioteca::adicionaObraArquivo(string nome) { // Cria uma obra nova e a adiciona na lista de obras
			Obra nova(nome);

			for (int i = 0; i < nova.obtemNumAutor(); i++)
				autores.push_back(nova.obtemAutor(i));

			sort(autores.begin(), autores.end());
			autores.erase(unique(autores.begin(), autores.end()), autores.end());
			obras.push_back(nova);
		}

		void Biblioteca::adicionaObraTeclado() { // Método para adicionar obra pelo teclado
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

			string choice;

			while (choice != 'N') {
				cout << "\nDigite o nome do autor:" << endl;
				getline(cin, temp);
				nova.defineAutor(temp);

				cout << "\nDeseja adicionar outro autor? Digite 'S' para sim ou 'N' para não:" << endl;
				getline(cin, choice);

				if (choice != 'N' && choice != 'S') cout << "\nOpção inválida!" << endl;
			}

			for (int i = 0; i < nova.obtemNumAutor(); i++)
				autores.push_back(nova.obtemAutor(i));

			sort(autores.begin(), autores.end());
			autores.erase(unique(autores.begin(), autores.end()), autores.end());

			obras.push_back(nova);
		}

		string Biblioteca::obtemTitulos() { // Passa para um stringstream todos os títulos das obras que estão na lista de obras
			stringstream ss;
			ss << "Obras cadastradas:" << endl;
			for (int i = 0; i < obras.size(); i++)
				ss << obras[i].obtemTitulo() << endl;

			return ss.str();
		}

		string Biblioteca::obtemAutores() { // Retorna um stringstream com os autores cadastrados na Biblioteca
			stringstream ss;
			ss << "Autores cadastrados:" << endl;
			for (int i = 0; i < autores.size(); i++)
				ss << autores[i] << endl;

			ss << "\n";

			return ss.str();
		}

		string Biblioteca::obtemObras() { // Retorna um stringstream com todas obras que estão cadastradas na Biblioteca
			stringstream ss;
			for (int i = 0; i < obras.size(); i++) {
				ss << obras[i].obtemObra() << endl;
			}

			return ss.str();
		}

		void Biblioteca::searchTitulo(string titulo) {  //busca em toda a base de dados por parte do título da obra, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
			                         // busca por titulo, obra a obra
			int f = 0; //flag
			for (int j = 0; j < obras.size(); j++) {
				string str = obras[j].obtemTitulo(); //a string onde será buscada
				size_t achou = str.find(str1); // "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
				if (achou != string::npos) { // npos= no position, ou seja, se o resultado não for "no position" é pq achou
					f++; //o termo pesquisado foi encontrado pelo menos uma vez
					cout << "O termo "
						<< str1
						<< " ocorre na obra: " << obras[j].obtemTitulo() << endl;
				}

			}

			if(f == 0) cout << "O termo " << str1 << " não foi encontrado na base de dados." << endl;
		}

		void Biblioteca::searchAutor(string autor) { //busca em toda a base de dados por parte do nome do autor, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
						// busca por autor, obra a obra
			int f = 0; //flag
			for (int j = 0; j < obras.size(); j++) {
				for (int k = 0; k < obras[j].obtemNumAutor(); k++) { //buscar em cada um dos autores
					string str = obras[j].obtemAutor(k); //a string onde será buscada
					size_t achou = str.find(str1); // "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
					if (achou != string::npos) { // npos= no position, ou seja, se o resultado não for "no position" é pq achou
						f++; //o termo pesquisado foi encontrado pelo menos uma vez
						cout << "O autor "
							<< str1
							<< " aparece na obra: " << obras[j].obtemTitulo() << endl;
						break; //achou já, não vai ter outro com o mesmo nome
					}

				}

			}

			if(f == 0) cout << "O nome " << str1 << " não foi encontrado na base de dados." << endl;
		}

		void Biblioteca::searchObras(int a1, int a2){ // Procura obras entre 2 anos oferecidos pelo usuário
			for(int i = 0; i < obras.size(); i++)
				if(obras[i].obtemAno() >= a1 && obras[i].obtemAno() <= a2)
					cout << obras[i].obtemObra() << endl;

		}

		int Biblioteca::porAno(int ano){ // Procura todas as obras lançadas no ano oferecido pelo usuário, conta quantas são e retorna o número
			int qtd = 0;									// para o usuário
			for(int i = 0; i < obras.size(); i++){
				if(obras[i].obtemAno() == ano){
					qtd++;
				}
			}
			return qtd;
		}

		int Biblioteca::porAutor(string autor){ // Procura por todas as obras produzidas pelo autor oferecido pelo usuário, conta quantas são
			int qtd = 0;								     // e retorna o número para o usuário
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

		void Biblioteca::toGraph() { // Produz o grafo
			for (int i = 0; i < autores.size(); i++) { // Percorre cada autor que está cadastrado
				for (int j = 0; j < obras.size(); j++) { // Procura por obras em que esse autor figure
					vector<string> tmp = obras[j].obtemAutores(); // Cria um vector temporário que recebe os autores da obra em questão
					for (int k = 0; k < tmp.size(); k++) { // Procura pelo autor no vector temporário
						if (tmp[k] == autores[i]) {
							tmp.erase(tmp.begin() + k); // Remove-o desse vector temporário
							for (int l = 0; l < tmp.size(); l++) { // Percorre o vector temporário novamente
								for (int m = 0; m < autores.size(); m++) { // Percorre o vector de autores
									if (tmp[l] == autores[m]) { // Caso ache algum autor relacionado
											grafo.addEdge(i, m, 1);
											grafo.addEdge(m, i, 1);
									}	// Cria a lista de adjacências do autor 'i' (método da classe Grafo)
								}
							}
						}
					}
				}
			}
		}

		void Biblioteca::visualizaDistancias(string nome) { // Mostra na tela as todas as distâncias entre o autor oferecido pelo usuário
			toGraph(); // Produz o grafo								// e todos os autores cadastrados
			for (int i = 0; i < autores.size(); i++) { // Verifica se o autor informado está cadastrado na base
				string str = autores[i];
				size_t achou = str.find(nome);
				if (achou != string::npos) { // Se o autor oferecido for encontrado na base
					for (int j = 0; j < autores.size(); j++) {
						if (autores[i] != autores[j]) {
							int distancia = grafo.dijkstra(i, j); // Método da classe Grafo que retorna a distância
							if (distancia == 10000000)	     // entre um autor e outro
								cout << "\nA distância de " << autores[i] << " para " << autores[j] << " é infinito." << endl;

							else cout << "\nA distância de " << autores[i] << " para " << autores[j] << " é " << distancia << "." << endl;

						}
					}

					return;
				}

			}

			cerr << "\nAutor não cadastrado na Biblioteca!" << endl;
		}


		void Biblioteca::toGraphviz(string arquivo) { // Produz um arquivo .txt que é formatado para funcionar no Graphviz
			toGraph(); // Produz o grafo
			stringstream ss;

			ss << "digraph G { " << endl;;
			for (int i = 0; i < autores.size(); i++) {
				for (int j = 0; j < autores.size(); j++) {
					if (autores[i] != autores[j]) {
						int distancia = grafo.dijkstra(i, j);
						if (distancia == 1) {
							ss << "  \"" << autores[i] << "\"" << " -> " << "\"" << autores[j] << "\" " << endl;
						}

					}

				}

			}

			ss << "}       ";

			ofstream arq;
			arquivo = arquivo + ".txt";
			arq.open(arquivo, ios::out);

			if (!arq.is_open()) {
				cerr << "\nArquivo inválido!" << endl;
				arq.close();
				return;
			}


			arq << ss.str(); // Salva no arquivo
			arq.close();
			cout << "\nArquivo exportado com sucesso! Para lê-lo, acesse: www.webgraphviz.com" << endl;
		}


