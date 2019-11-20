//inspirado no programa disponível em "https://gist.github.com/marcoscastro/d4e0df5b134c2cd63cf2"
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define INFINITO 10000000

using namespace std;

class Grafo
{
	private:
		int V; // número de vértices
		typedef list<pair<int, int>> lista;// o contâiner lista (de ajdacências) está armazenando o contâiner pair (é uma lista de pares)... 

		// e pares são úteis, no caso de grafos, pois cada aresta (edge) é um caminho entre dois pontos 

		lista VetorListas[1000]; //...o contâiner vector(VetorListas) deveria conter essas litas, mas, APÓS MAIS DE MUITAS HORAS, EU DESISTI DE VECTOR E ESTOU USANDO ARRAY MESMO.
		
	public:

		Grafo(int V)
		{
			this->V = V; //mais adiante ficará claro porque precisamos definir o número de vértices.
			for (int i=0; i<1000;i++){
			VetorListas[i]={};
			}
		}


		// adiciona uma aresta ao nosso grafo, indo do nodo v1 ao nodo v2
		void addEdge(int v1, int v2, int custo)// são três argumentos, mas o primeiro, v1, representa o índice do vetor de listas...
			//... o segundo, v2, é o nodo com quem ele se relaciona e o terceiro é o custo do caminho (sempre 1, no caso)
		{	
//			custo=1;// não troquei o número de argumentos para deixar o código genérico 
			lista aux= VetorListas[v1];//lista auxiliar em que serão feitas as alterações
			aux.push_back(make_pair(v2,custo));
			VetorListas[v1]=aux;//o elemento v1, que, repiso, é o índice do vetor de listas, recebe a lista atualizada
		}// 

		// algoritmo de Dijkstra
		int dijkstra(int orig, int dest)// calcula a distância entre os dois nodos fornecidos
		{
			// vetor de distâncias
			int distancia[V];

			// vetor de visitados 
			int visitados[V];

			// fila de prioridades de pair (distancia, vértice)
			priority_queue < pair<int, int>,
				       vector<pair<int, int> >, greater<pair<int, int> > > pq;

			// inicializa os vetor de distâncias e visitados, definindo todas as distâncias como infinitas e 
			// não tendo sido nenhum nodo visitado
			for(int i = 0; i < V; i++)
			{
				distancia[i] = INFINITO;
				visitados[i] = false;
			}

			// a distância de orig para orig é 0
			distancia[orig] = 0;

			// insere na fila
			pq.push(make_pair(distancia[orig], orig));

			// loop do algoritmo
			while(!pq.empty())
			{
				pair<int, int> p = pq.top(); // extrai o pair do topo
				int u = p.second; // obtém o vértice do pair
				pq.pop(); // remove da fila

				// verifica se o vértice não foi visitado
				if(visitados[u] == false)
				{
					// marca como visitado
					visitados[u] = true;

					list<pair<int, int> >::iterator it;

					// percorre os vértices "v" adjacentes a "u"
					
					for(auto it = VetorListas[u].begin(); it != VetorListas[u].end(); it++)
					{
						// obtém o vértice adjacente e o custo da aresta
						int v = it->first;
						int custo_aresta = it->second;
						// relax (u, v)
						if(distancia[v] > (distancia[u] + custo_aresta))
						{
							// atualiza a distância de "v" e insere na fila
							distancia[v] = distancia[u] + custo_aresta;
							pq.push(make_pair(distancia[v], v));
						}
					}
				}
			}

			// retorna a distância mínima até o destino
			return distancia[dest];
		}
};
