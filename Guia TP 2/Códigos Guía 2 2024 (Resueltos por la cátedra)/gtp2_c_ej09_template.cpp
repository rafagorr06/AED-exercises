#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

/// isHamilt. Dado un grafo map<int, list<int> >G y una lista de vertices list<int> L determinar
/// si L es un camino hamiltoniano en G.
bool is_hamilt(map<int,list<int>>& G, list<int>& L) {
	/// def. un camino es Hamiltoniano si pasa por todos los nodos 
	/// del grafo una sola vez (sin repeticiones)
	return true;
}
 
int main(int argc, char *argv[]) {
	map<int, list<int>> G = {
		{1, {2,6}},
		{2, {1,3,4,5}},
		{3, {2,5,7}},
		{4, {2,6}},
		{5, {2,3}},
		{6, {1,4,7}},
		{7, {3,6}}
	};
	list<int> LH = {1,6,4,2,5,3,7};
	cout<< "LH es camino hamiltoniano? "<< is_hamilt(G,LH)<<endl;
	graph2dot(G);
	return 0;
}
