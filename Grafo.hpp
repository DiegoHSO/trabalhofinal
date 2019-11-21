//Grafo.hpp (Diego Henrique, Icaro Stumpf, Samuel Nascimento; 21 nov. 2019)
#ifndef _DIJKSTRAHPP_
#define _DIJKSTRAHPP_

//inspirado no programa disponível em "https://gist.github.com/marcoscastro/d4e0df5b134c2cd63cf2"
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Grafo
{
	private:
		int V; 
		typedef list<pair<int, int>> lista; 
		lista VetorListas[1000]; 
	public:

		Grafo();

		void addEdge(int v1, int v2, int custo); 

		int dijkstra(int orig, int dest);
};
#endif
