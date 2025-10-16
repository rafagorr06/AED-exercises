#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <list>
using namespace aed;
using namespace std;


template<typename T>
void show_list(const list<T> &L){
	cout << "[ ";
	for_each(L.begin(),L.end(),[](T v){cout << v << " ";});
	cout << "] \n";
}
		
void prefijo(tree<int> &arbol, tree<int>::iterator p,list<int> &L){

	if (p == arbol.end()) return;
	L.push_back(*p);

	tree<int>::iterator c = p.lchild();
	while (c != arbol.end()) prefijo(arbol,c++,L);
}	
	
void postfijo(tree<int> &arbol,typename tree<int>::iterator p,list<int> &L){
	if (p == arbol.end()) return;		
	tree<int>::iterator c = p.lchild();
	while (c != arbol.end()) postfijo(arbol,c++,L);
	L.push_back(*p);
}		
	
	int main()
	{			
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8) (5 9 (13 10))");
	tree<int> arbol;	
	
	if (lisp2tree(s_arbol,arbol)) tree2dot(arbol);
	else cout << "Error en crear arbol a partir de notacion de lisp \n";

	cout << "prefijo:  ";
	
	list<int> L;
	tree<int>::iterator it = arbol.begin();
	prefijo(arbol,it,L);	
	show_list(L);	
	
	cout << "postfijo: ";
	L.clear();
	it = arbol.begin();
	postfijo(arbol,it,L);
	show_list(L);	
	
	return 0;
	}
