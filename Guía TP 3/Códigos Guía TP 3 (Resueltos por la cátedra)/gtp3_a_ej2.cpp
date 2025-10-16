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
	
void altura(tree<int> &arbol, tree<int>::iterator it, int prof, int &alt)
{
	if (it == arbol.end())
	{		
		return;
	}
	
	tree<int>::iterator c = it.lchild();
		
	while (c != arbol.end()) {
		altura(arbol, c, prof+1, alt);
		c++;
	}
	
	if (alt < prof +1) {
		alt = prof +1;
	}
}

void contar_hojas(tree<int> &arbol, tree<int>::iterator it, int &n_hojas)
{	
	if (it == arbol.end())
	{					
		return;
	}
	
	tree<int>::iterator c = it.lchild();
	if (c == arbol.end())
		n_hojas++;
	
	while (c != arbol.end()) {
		contar_hojas(arbol, c, n_hojas);
		c++;
	}	
}

void etiqueta_maxima(tree<int> &arbol, tree<int>::iterator it, int &et_max)
{
	if (it == arbol.end())
	{					
		return;
	}
	
	if (*it > et_max)
		et_max = *it;
	
	tree<int>::iterator c = it.lchild();
	
	while (c != arbol.end()) {
		etiqueta_maxima(arbol, c, et_max);
		c++;
	}	
}

void etiqueta_maxima_par(tree<int> &arbol, tree<int>::iterator it, int &et_max)
{
	if (it == arbol.end())
	{					
		return;
	}
	
	if (*it > et_max && *it%2 == 0)
		et_max = *it;
	
	tree<int>::iterator c = it.lchild();
	
	while (c != arbol.end()) {
		etiqueta_maxima_par(arbol, c, et_max);
		c++;
	}	
}



void suma_etiquetas(tree<int> &arbol, tree<int>::iterator it, int &suma)
{
	suma += *it;
	if (it == arbol.end())
	{					
		return;
	}
	tree<int>::iterator c = it.lchild();
	
	while (c != arbol.end()) {		
		suma_etiquetas(arbol, c, suma);	
		c++;
	}	
	
}


void purge_odd(tree<int> &arbol, tree<int>::iterator it )
{		
	while (it != arbol.end())
	{
		if(*it%2){ 			
			it = arbol.erase(it);
		}
		else {
			auto it2 = it.lchild();
			if (it2 != arbol.end())
			{
				purge_odd(arbol,it2);				
			}
			it++;	
		}		
	}
}

	
int main()
	{			
	string s_arbol("(10 2 (3 6 (7 11 12))(4 8) (6 9 (41 10))");
	//string s_arbol("(1)");
	tree<int> arbol;	
	
	if (!lisp2tree(s_arbol,arbol)) 
	{
	 cout << "Error en crear arbol a partir de notacion de lisp \n";
	 return -1;
	}
	tree2dot(arbol, "arbol_completo");
	
	int alt = 0;
	altura(arbol, arbol.begin(),0,alt);
	
	int n_hojas = 0;
	contar_hojas(arbol, arbol.begin(),n_hojas);
	
	int et_max= -1;
	etiqueta_maxima(arbol, arbol.begin(),et_max);

	int et_max_par= -1;
	etiqueta_maxima_par(arbol, arbol.begin(),et_max_par);
	
	int suma = 0;
	suma_etiquetas(arbol, arbol.begin(),suma);
	
	cout << "altura: "<<alt << endl;
	cout << "n_hojas: "<<n_hojas<< endl;
	cout << "et_max: "<<et_max<< endl;
	cout << "et_max_par: "<<et_max_par<< endl;
	cout << "suma: "<<suma<< endl;
	
	purge_odd(arbol, arbol.begin());	
	tree2dot(arbol,"arbol_sin_impares");	
	
	return 0;
	}
