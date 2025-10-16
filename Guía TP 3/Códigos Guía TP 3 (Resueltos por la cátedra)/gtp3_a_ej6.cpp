#include <iostream>
#include <map>
#include <tree.hpp>
#include <lisp.hpp>
#include <list>
#include <graphviz.hpp>
#include <climits>

using namespace aed;
using namespace std;

template<typename T>
void show_list(const list<T> &L){
	cout << "[ ";
	for_each(L.begin(),L.end(),[](T v){cout << v << " ";});
	cout << "] \n";
	}


	/// Funciones predicado
bool odd(int x) 
{
	return x % 2;
}
	
bool positive(int x) 
{
	return x > 0;
}
	
bool negative(int x) 
{
	return x < 0;
}	

void listar_si(tree<int> &T, tree<int>::iterator n, list<int> &L, bool (*pred)(int x))	
{
	if (n == T.end()) return;
	if (pred(*n)) L.push_back(*n);
	
	tree<int>::iterator c = n.lchild();
	while (c != T.end())
	{
		listar_si(T,c,L,pred);
		c++;
	}	
}
	
void listar_si(tree<int> &T, list<int> &L, bool (*pred)(int x))	
{
	return listar_si(T,T.begin(), L, pred);
}

int main()
{
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8) (5 9 (13 10))");
	tree<int> arbol;
	if (lisp2tree(s_arbol,arbol)) tree2dot(arbol);
	
	else cout << "Error en crear arbol a partir de notacion de lisp \n";
	
	list<int> L;
	listar_si(arbol, L, odd);
	cout << "Lista nodos impares: ";
	show_list(L);
	

}
