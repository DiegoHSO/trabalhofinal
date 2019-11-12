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
		string arquivo;// para poder chamar o nome do arquivo que corresponde ao objeto, na busca.
		int numAutores;// para facilitar a busca por autores
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
			this->arquivo=nome; //vide o private
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
			this->numAutores=autores.size();//vide o privado
			arq.close();

		}

		void mostrarAutores() {//não entendi o 6, troquei por função que dá o no de elemtos do vector
			for (int i = 0; i < autores.size(); i++) cout << "Autor:" << autores[i] << endl;
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

		string obtemArquivo(){//criei, vide privado
			return arquivo;
		}

		string obtemAutor(int n){//criei para poder fazer a pesquisa por autor
			return autores[n];
		}

		int obtemNumAutor(){//criei para facilitar a pesquisa por autor
			return numAutores;
		}


};
		
		void imprimeLinha(){
			cout <<"-----------------------------------------------"<<endl;
		}
void searchTitulo (vector<Obra> obras, string str1){//busca em toda a base de dados por parte do título da obra, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
	// busca por titulo, obra a obra
	//int=0;
	int f=0;//flag
	for (int j=0; j<obras.size(); j++){
		string str=obras[j].obtemTitulo(); //a string onde será buscada
		size_t achou =str.find(str1);// "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
		if (achou != string::npos) {// npos= no position, ou seja, se o resultado não for "no position" é pq achou
			f++;//o termo pesquisado foi encontrado pelo menos uma vez
			cout << "O termo "
				<< str1 
				<< " ocorre na obra: " << obras[j].obtemTitulo() << endl;
			cout<< "Seu registro, no Google Scholar, no formato EndNote, é o que segue:"<<endl;
			imprimeLinha();
			ifstream f(obras[j].obtemArquivo());
			if (f.is_open())cout << f.rdbuf();//imprime todo o conteúdo do arquivo na tela
			imprimeLinha();
			/*while(1){
				achou = str.find(str1, achou+1); 
				if (achou != string::npos){ 
					i++;	
					cout << "A "<< i<<"ª ocorrência de " << str1 << " ocorre na obra: "<< obras[j].obtemTitulo() << endl; 
				}
				else break;
			} */
		}

	} 
		if(f==0) cout <<"O termo "<< str1 << " não foi encontrado na base de dados."<<endl;
}
void searchAutor (vector<Obra> obras, string str1){//busca em toda a base de dados por parte do nome do autor, EXIBINDO OS DADOS DESSA OBRA, conforme é solicitado no enunciado
	// busca por autor, obra a obra
	//int=0;
	int f=0;//flag
	for (int j=0; j<obras.size(); j++){
		for (int k=0;k<obras[j].obtemNumAutor(); k++){//buscar em cada um dos autores 
		string str=obras[j].obtemAutor(k); //a string onde será buscada
		size_t achou =str.find(str1);// "size_t achou" armazenará o índice do resultado da busca por str1 dentro de str. 
		if (achou != string::npos) {// npos= no position, ou seja, se o resultado não for "no position" é pq achou
			f++;//o termo pesquisado foi encontrado pelo menos uma vez
			cout << "O autor "
				<< str1 
				<< " aparece na obra: " << obras[j].obtemTitulo() << endl;
			cout<< "Seu registro, no Google Scholar, no formato EndNote, é o que segue:"<<endl;
			imprimeLinha();
			ifstream f(obras[j].obtemArquivo());
			if (f.is_open())cout << f.rdbuf();//imprime todo o conteúdo do arquivo na tela
			imprimeLinha();
			break;//achou já, não vai ter outro com o mesmo nome
			/*while(1){
				achou = str.find(str1, achou+1); 
				if (achou != string::npos){ 
					i++;	
					cout << "A "<< i<<"ª ocorrência de " << str1 << " ocorre na obra: "<< obras[j].obtemTitulo() << endl; 
				}
				else break;
			} */
		}

	} 

}
		if(f==0) cout <<"O nome "<< str1 << " não foi encontrado na base de dados."<<endl;
}
int main () {
	vector<Obra> obras;
	cout << "Adicionando arquivos no formato .enw:" << endl;
	string	string1="ney.enw";
	string	string2="ney2.enw";
	string	string3="ney3.enw";
	Obra nova(string1);
	obras.push_back(nova);
	Obra nova2(string2);
	obras.push_back(nova2);
	Obra nova3(string3);
	obras.push_back(nova3);
	string str1;
	string str2;
	cout << "Digite parte do título a ser buscado na base de dados."<<endl;
	cin >> str1;
	searchTitulo (obras, str1);
	cout << "Digite o nome do autor a ser buscado na base de dados."<<endl;
	cin >> str2;
	searchAutor (obras, str2);
	return 0;

}



