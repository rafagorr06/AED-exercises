#include <iostream>
#include <vector>
#include <list>
using namespace std;

//3) Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
//	lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice. Cada
//	procedimiento debe retornar el resultado en una lista nueva.

list<int> concatenar_a (const list<int>&L1 , const list<int>&L2){
	list<int>lista_concatenada;
	lista_concatenada.insert(lista_concatenada.end(),L1.begin(),L1.end());
	lista_concatenada.insert(lista_concatenada.end(),L2.begin(),L2.end());
	return lista_concatenada;
}
	
list<int> concatenar_b (const list<list<int>>&LL){
	list<int>lista_concatenada;
	for(const auto &sublista : LL){
		lista_concatenada.insert(lista_concatenada.end(),sublista.begin(),sublista.end());
	}
	return lista_concatenada;
}
	
list<int> concatenar_c (const list<list<int>>&LL){
	list<int>lista_concatenada;
	for(auto sublista : LL){
		lista_concatenada.splice(lista_concatenada.end(),sublista);
	}
	return lista_concatenada;
}

////////
	
void imprimir_lista(const list<int> &L) {
	for (auto it = L.begin(); it != L.end(); ++it) {
		cout << *it << " ";
	}
	cout << "";
}	
	
void imprimir_lista_de_lista(const list<list<int>> &LL) {
	cout << "[";
	for (auto it = LL.begin(); it != LL.end(); ++it) {
		cout << "[";
		for (auto elem : *it) cout << elem << " ";
		cout << "]";
		if (next(it) != LL.end()) cout << ", ";
	}
	cout << "]" << endl;
}

///////

int main() {
	cout << "a) Concatenar dos listas L1 y L2 usando insert" << endl;
	list<int> L1 = {1, 2, 3};
	list<int> L2 = {4, 5, 6};
	
	cout << "L1 = "; imprimir_lista(L1);
	cout << "L2 = "; imprimir_lista(L2);
	
	list<int> resultado_a = concatenar_a(L1, L2);
	cout << "Resultado: "; imprimir_lista(resultado_a);
	cout << endl;
	
	//
	
	cout << "b) Concatenar lista de sublistas usando insert" << endl;
	list<list<int>> LL_b = {{1, 2}, {3, 4, 5}, {6}, {7, 8, 9, 10}};
	cout << "LL = "; imprimir_lista_de_lista(LL_b);
	list<int> resultado_b = concatenar_b(LL_b);
	cout << "Resultado: [ "; imprimir_lista(resultado_b); cout << "]";
	cout << endl;
	
	//
	
	cout << "c) Concatenar lista de sublistas usando splice" << endl;
	list<list<int>> LL_c = {{1, 2}, {3, 4, 5}, {6}, {7, 8, 9, 10}};
	cout << "LL antes: "; imprimir_lista_de_lista(LL_c);
	list<int> resultado_c = concatenar_c(LL_c);
	cout << "Resultado: [ "; imprimir_lista(resultado_c); cout << "]";
	
	return 0;
}







