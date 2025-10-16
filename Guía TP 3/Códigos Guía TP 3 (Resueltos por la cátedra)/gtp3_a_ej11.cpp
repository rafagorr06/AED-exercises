#include <iostream>
#include <map>
#include <tree.hpp>
#include <list>
#include <graphviz.hpp>
#include <climits>

using namespace aed;
using namespace std;

typedef map<char, map<char,int>> graphW;
/// {'A',{{'B',2},{'C',3},}

const int INF = INT_MAX;

int Prim(graphW& G, tree<char>& T)
{
	int peso = 0;
	map<char, tree<char>::iterator> visitados;	
	tree<char>::iterator it = T.begin();
	
	/// agregar el primer vertice a vertices visitados	
	it = T.insert(it, G.begin()->first);
	visitados[G.begin()->first] = it;
	
	graphW::iterator iG = G.begin();
	
	/// iterar hasta que el arbol tenga la misma cantidad de nodos que el grafo original
	while (visitados.size() < G.size())
	{
		iG = G.begin();
		int currentMin = INF;
		char currNodo, currAdy;
		for (int i = 0; i < G.size(); i++)
		{
			/// recorrer nodos adyacentes a los visitados y quedarnos con la arista de menor costo
			char nodoActual = iG->first;
			if(visitados.find(nodoActual) != visitados.end())
			{
				map<char, int>& adyacentes = iG->second;
				map<char, int>::iterator iA = adyacentes.begin();
				
				for (int j = 0; j<adyacentes.size(); j++)
				{
					char nodoAdyacente = iA->first;
					/// OJO: no formar ciclos				
					if (currentMin > G[nodoActual][nodoAdyacente] && visitados.find(nodoAdyacente) == visitados.end())
					{
						currentMin = G[nodoActual][nodoAdyacente];
						currNodo = nodoActual;
						currAdy = nodoAdyacente;
					}					
					iA++;
				}				
			}
			iG++;
		}
		///cada vez que agregamos una arista, actualiza costo acumulado
		peso += currentMin;
		it = T.insert(visitados[currNodo].lchild(),currAdy);		
		visitados[currAdy]	= it;
	}
		
	return peso;
}

int main()
{
	graphW G = 
	{
		{'A',
		{
			{'B',2},
		{'C',3},
		}
	},
	{'B',
	{
		{'D',5},
	{'E',2},
		{'A',2},
	}
	},
		{'C',
		{
			{'A',3},
		{'E',5},
		}
		},
	{'D',
	{
		{'B',5},
	{'E',1},
		{'Z',2},
	}
	},	
		{'E',
		{
			{'C',5},
		{'B',2},
			{'D',1},
		{'Z',4},
		}
		},
	{'Z',
	{
		{'D',2},
	{'E',4},				
	}
	},
	};
	
	tree<char> arbol;
	cout << Prim(G,arbol);	
	
	tree2dot(arbol);	
}
�