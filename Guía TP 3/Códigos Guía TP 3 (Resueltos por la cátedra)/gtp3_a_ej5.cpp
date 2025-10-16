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

int contar_si(tree<int> &T, tree<int>::iterator n, bool (*pred)(int x))	
{
	if (n == T.end()) return 0;
	int count = pred(*n);
	
	tree<int>::iterator c = n.lchild();
	while (c != T.end())
	{
		count += contar_si(T,c,pred);
		c++;
	}
	return count;
}
	
int contar_si(tree<int> &T, bool (*pred)(int x))	
{
	return contar_si(T,T.begin(),pred);
}

int main()
{
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8) (5 9 (13 10))");
	tree<int> arbol;
	if (lisp2tree(s_arbol,arbol)) tree2dot(arbol);
	
	else cout << "Error en crear arbol a partir de notacion de lisp \n";
	
	int count_odd = contar_si(arbol, odd);
	cout << "Cantidad de nodos impares: " << count_odd << endl;
	

}
