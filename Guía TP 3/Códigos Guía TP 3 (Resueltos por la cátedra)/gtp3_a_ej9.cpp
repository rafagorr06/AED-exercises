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
	
	//auxiliar
	void crea(double M, int n, int g, tree<double> T, tree<double>::iterator nodo)
	{
	if (*nodo < n) return;
	tree<double>::iterator it = nodo.lchild();
	
	for (int i = 0; i < g; i++)
	{
		double MM = M/g;		
		it = T.insert(it,MM);
		crea(MM, n, g, T, it);
	}
	
	}
	
	//wrapper
	tree<double> crea(double M, int n, int g) 
	{
		tree<double> T;
		tree<double>::iterator it = T.begin();
		it = T.insert(it,M);
		crea(M,n,g,T,it);
		return T;
	}
	
	int main()
	{
		tree<double> T = crea(10,2,3);
		tree2dot(T);				
		
	}
