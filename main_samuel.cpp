#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

#include "ReadArq.hpp"

//  PRECISA DE ReadArq.cpp ReadArq.hpp Arquivo2.enw

using namespace std;

const int TAM = 6;
const int OBRAS = 5;

int main(){
    ifstream read;
    cout << "Lendo arquivo ..." << endl << endl;
    read.open("Arquivo2.enw", ios::in);
    if(!read.is_open()){
        return 1;
    }
    string s[TAM];
    int n, c = 0;
    ReadArq *novo = new ReadArq[OBRAS];
    do {
        for(int i = 0; i < TAM; i++){
            getline(read, s[i]);            
        }
        for(int i = 0; i < TAM; i++){
            if(!read.fail()){
                cout << i << " " << s[i] << endl;
            }
        }
        novo[c].defineObra(s[0]);
        novo[c].defineTitulo(s[1]);
        novo[c].defineAutor(s[2]);
        novo[c].defineLocal(s[3]);
        novo[c].defineVersao(s[4]);
        stringstream geek(s[5]);
        geek >> n;
        novo[c].defineAno(n);
        c++;
        cout << endl;
       
    } while(read.good());

    if(read.bad() != !read.eof()){
        cerr << "Error!" << endl;
        exit(1);
    }

    cout << "Fechando arquivo ..." << endl;
    read.close();    

    for(int i = 0; i < OBRAS; i++){
        cout << novo[i].toString() << endl;
    }

    cout << "1. Busca por nome ou titulo da obra" << endl;
    cout << "2. Consulta de obras publicadas entre dois anos" << endl;
    cout << "3. Quantidade de obras por ano e por autor" << endl;

    int select = 0;
    cin >> select;
    
   /* switch (select){
    case 1:
        cout << "Digite o nome ou titulo da obra" << endl;
        string nome;
        getline(cin,nome);
        for(int i = 0; i < OBRAS; i++){
            for(int j = 0; j < OBRAS; j++){
                for(int k = 0; k < OBRAS; k++){
                    novo[i].obtemObra();
                }
            }
        }
        break;    
    case 2:      
        break;
    case 3:       
        break;
    default:
        break;
    }*/

    delete [] novo;

    return 0;
}