#include <iostream>
#include <btree.hpp>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;


/// Auxiliar
bool contenido(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	/// retorna verdadero si la estructura del arbol binario A esta
	/// contenido dentro de la de B y las etiquetas correspondientes de
	/// A son menores que las de B.
	
	/// itA no tiene ningun valor, no importa
	/// lo que itB tenga
	if(itA == A.end()) return true;
	
	/// itA tiene un valor pero itB no
	if(itB == B.end()) return false;

	/// itB no tiene que ser mayor a itA
	if(*itB < *itA) return false;
	
	/// se evalua la estructura de cada hijo
	/// en forma recursiva
	if(!contenido(A, itA.left(), B, itB.left())) return false;
	if(!contenido(A, itA.right(), B, itB.right())) return false;
	
	return true;
}

/// Wrapper
bool contenido(btree<int>& A, btree<int>& B) {
	return contenido(A, A.begin(), B, B.begin());
}



int main() {
	
	btree<int> BT1, BT2;
	
//	lisp2btree("(4 (9 4 6) (7 2 3))", BT1);
//	lisp2btree("(4 (9 4 6) (8 3 4))", BT2);
//	
//	btree2dot(BT1, "BT1");
//	btree2dot(BT2, "BT2");
//	
	
	lisp2btree("(4 (9 . 8) (5 7 8))", BT1);
	lisp2btree("(4 (10 7 8) (6 8 9))", BT2);
	
	btree2dot(BT1, "BT1");
	btree2dot(BT2, "BT2");
	
	cout<<"se cumple contenido? "<<contenido(BT1, BT2)<<endl;
	
	return 0;
}

