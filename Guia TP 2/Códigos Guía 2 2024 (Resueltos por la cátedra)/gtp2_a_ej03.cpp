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
	list<int>::iterator last = L.begin();
	while (next(last) != L.end())
	{
		last = next(last);
	}
	while (first != last)
	{
		L.insert(next(last), *first);
		L.erase(first);
		first = L.begin();		
	}
}


int main(int argc, char *argv[]) {
	list<int> L = {1,4,6,2,4,8,9,33};
	
	//selection_sort(L);
	
	//show_list(L);
	
	//list<int> L;
	
	list<int> L1 = {1,2,3,4};
	list<int> L2 = {7,6,5};
	
	//list<int> L = concatA(L1,L2);
	
	list<list<int>> LL = {{1,2,3}, {6,7,8}, {6,5,4}};
	
	//concatB(LL, L);
	
	//concatC(LL, L);
	
	//list<int> L = {1,2,3,4,5,6,7};
	//list<int> L;
	
	invert2(L);
	
	show_list(L);
	
	
	return 0;
}
