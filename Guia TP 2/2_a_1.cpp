#include <iostream>
#include <list>
using namespace std;

//1) BasicSort. Escribir una función void basic_sort(list<int> &L), que ordena los elementos de L
//	de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
//	tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vac\u0131\u0301a.
//	Luego insertar los elementos de L2 en L.

void basic_sort(list<int> &L) {
	list<int>L2;
	while(!L.empty()){
		auto minimo = L.begin();
		auto it = L.begin();
		++it;
		
		while(it!=L.end()){
			if(*it < *minimo){
				minimo = it;
			}
			++it;
		}
		L2.push_back(*minimo);
		L.erase(minimo);
	}
	L=L2;
}

void imprimir_lista(const list<int> &L) {
	for (auto it = L.begin(); it != L.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}


int main() {
	list<int> L1 = {5, 2, 8, 1, 9, 3};
	cout << "Lista original: ";
	imprimir_lista(L1);
	
	basic_sort(L1);
	cout << "Lista ordenada: ";
	imprimir_lista(L1);
	cout << endl;
	return 0;
}







