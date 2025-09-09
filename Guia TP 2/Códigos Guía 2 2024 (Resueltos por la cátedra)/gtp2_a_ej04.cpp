#include <iostream>
#include <list>
using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

///Invierte. Escribir una funcion void invert(list<int> &L), que invierte el 
///orden de la lista L.	Este algoritmo debe implementarse in place y debe ser O(n).
///Restriccionn: no utilizar el metodo size().
void invert(list<int> &L)
{
	list<int>::iterator first = L.begin();
	list<int>::iterator current = L.begin();
	while (next(current) != L.end())
	{
		current = next(current) ;
		L.insert(L.begin(), *current);				
	}
	current = first;
	
	
	while (next(first) != L.end())
	{
		current = next(first);
		L.erase(current);
	}
	
}


int main(int argc, char *argv[]) {
	list<int> L = {1,4,6,2,4,8,9,33};
	
	invert(L);
	
	show_list(L);
	
	
	return 0;
}
