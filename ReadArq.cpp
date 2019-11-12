#include "ReadArq.hpp"

ReadArq::ReadArq(string s1, string s2, string s3, string s4, string s5, int a){
    obra = s1;
    titulo = s2;
    autor = s3;
    local = s4;
    versao = s5;
    ano = a;
}

ReadArq::~ReadArq(){}

ReadArq::ReadArq(){}

void ReadArq::defineObra(string s){
    obra = s;
}

void ReadArq::defineTitulo(string s){
    titulo = s;
}

void ReadArq::defineAutor(string s){
    autor = s;
}

void ReadArq::defineLocal(string s){
    local = s;
}

void ReadArq::defineVersao(string s){
    versao = s;
}

void ReadArq::defineAno(int a){
    ano = a;
}

string ReadArq::obtemObra(){
    return obra;
}

string ReadArq::obtemTitulo(){
    return titulo;
}

string ReadArq::obtemAutor(){
    return autor;
}

string ReadArq::obtemLocal(){
    return local;
}

string ReadArq::obtemVersao(){
    return versao;
}

int ReadArq::obtemAno(){
    return ano;
}

string ReadArq::toString(){
    stringstream ss;
    ss << "Obra: " << obra << endl;
    ss << "Titulo: " << titulo << endl;
    ss << "Autor: " << autor << endl;
    ss << "Local: " << local << endl;
    ss << "Versao: " << versao << endl;
    ss << "Ano: " << ano << endl;
    return ss.str();
}