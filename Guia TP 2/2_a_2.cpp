#include <iostream>
#include <list>
using namespace std;

//2) SelectionSort. Escribir una función void selection_sort(list<int> &L), que ordena los
//	elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
//	(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
//	restante, con el segundo elemento, y as\u0131\u0301 sucesivamente. Esta función debe ser IN PLACE.

void selection_sort(list<int> &L){
	auto actual = L.begin();
	
	while(actual != prev(L.end())){
		auto minimo = actual;
		auto it = next(actual);
		
		while(it != L.end()){
			if(*it < *minimo){
				minimo = it;
			}
			++it;
		}
		
		if(minimo != actual){
			swap(*actual , *minimo);
		}
		++actual;
		
	}
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
	
	selection_sort(L1);
	cout << "Lista ordenada: ";
	imprimir_lista(L1);
	cout << endl;
	
	return 0;
}







