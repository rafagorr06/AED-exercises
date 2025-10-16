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

void orden_de_nivel(tree<int> &T, tree<int>::iterator p, int current_level, map<int,list<int>> &M)
{
	if (p==T.end()) return;	
	M[current_level].push_back(*p);	
	
	tree<int>::iterator c = p.lchild();	
	current_level ++;
	while (c != T.end())
	{		
		orden_de_nivel(T, c, current_level+1, M);		
		c++;
	}
	current_level--;	
}

list<int> orden_de_nivel(tree<int> &T)
{
	int current_level = 0;
	map<int, list<int>> M;	
	orden_de_nivel(T,T.begin(),current_level,M);
	
	list<int> L;
	map<int, list<int>>::iterator it = M.begin();	
	while (it != M.end()) 
	{
	L.insert(L.end(),it->second.begin(),it->second.end());
	it++;
	}
	return L;
}
int main()
{
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8) (5 9 (13 10))");
	tree<int> arbol;
	if (lisp2tree(s_arbol,arbol)) tree2dot(arbol);
	
	else cout << "Error en crear arbol a partir de notacion de lisp \n";
	
	list<int> L = orden_de_nivel(arbol);
	show_list(L);

}
