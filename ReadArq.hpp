#ifndef _READARQ_HPP
#define _READARQ_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ReadArq{
private:
    string obra;
    string titulo;
    string autor;
    string local;
    string versao;
    int ano;
public:
    ReadArq(string s1, string s2, string s3, string s4, string s5, int a);
    ReadArq();
    ~ReadArq();
    void defineObra(string s);
    void defineTitulo(string s);
    void defineAutor(string s);
    void defineLocal(string s);
    void defineVersao(string s);
    void defineAno(int a);
    string obtemObra();
    string obtemTitulo();
    string obtemAutor();
    string obtemLocal();
    string obtemVersao();
    int obtemAno();
    string toString();
};

#endif