#include <iostream>
#include <map>
#include <tree.hpp>
#include <lisp.hpp>
#include <list>
#include <graphviz.hpp>
#include <climits>

using namespace aed;
using namespace std;

void count_level(tree<int> &T, tree<int>::iterator p, int &nnodes, int &current_level, int l)
{	
if (p == T.end()) return;

if (current_level == l) 
	{	
	cout << "nodo " << *p << endl;
	nnodes++;		
	}

tree<int>::iterator c = p.lchild();
current_level++;

while (c!=T.end())	{		
	count_level(T,c,nnodes, current_level,l);		
	c++;
}
current_level--;
}

int count_level(tree<int> &T, int l)
{
	int nnodes = 0;	
	int current_level = 0;
	count_level(T, T.begin(), nnodes,current_level,2);	
	return nnodes;
}

int main()
{
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8) (5 9 (13 10))");
	tree<int> arbol;
	if (lisp2tree(s_arbol,arbol)) tree2dot(arbol);
	
	else cout << "Error en crear arbol a partir de notacion de lisp \n";
	cout << "nodos en nivel : " << count_level(arbol,2) << "\n";
}
