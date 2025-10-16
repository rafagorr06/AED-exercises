#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;

/// VariosAB. Escribir procedimientos para:
///	a Determinar si dos arboles tienen la misma estructura (semejantes).
/// b Determinar si la estructura de un arbol es la espejada de otro.
/// c Determinar si dos arboles son iguales, en estructura y contenido
/// d Copiar un arbol en otro en forma espejada.

/// Auxiliar
bool semejantes(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	/// xor
	/// a xor b = da verdadero si a!=b
	/// a xor b = da falso si a==b
	bool valorIzq, valorDer;
	
	if(itA == A.end() xor itB == B.end()) {
		return false;
	} else if(itA == A.end()) {
		return true;
	} else {
		valorIzq = semejantes(A, itA.left(), B, itB.left());
		valorDer = semejantes(A, itA.right(), B, itB.right());
		return (valorIzq && valorDer);
	}
}

/// Wrapper
bool semejantes(btree<int>& A, btree<int>& B) {
	return semejantes(A, A.begin(), B, B.begin());
}

/// Auxiliar
bool espejados(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	
	bool valorIzq, valorDer;
	if(itA == A.end() xor itB == B.end()) {
		return false;
	} else if(itA == A.end()) {
		return true;
	} else {
		valorIzq = espejados(A, itA.left(), B, itB.right());
		valorDer = espejados(A, itA.right(), B, itB.left());
		return (valorIzq && valorDer);
	}
}

/// Wrapper
bool espejados(btree<int>& A, btree<int>& B) {
	return espejados(A, A.begin(), B, B.begin());
}


/// Auxiliar
bool iguales(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	bool valorIzq, valorDer;
	
	if(itA == A.end() xor itB == B.end()) {
		return false;
	} else if(itA == A.end()) {
		return true;
	} else if(*itA != *itB) {
		return false;
	} else {
		valorIzq = iguales(A, itA.left(), B, itB.left());
		valorDer = iguales(A, itA.right(), B, itB.right());
		return (valorIzq && valorDer);
	}
}

/// Wrapper
bool iguales(btree<int>& A, btree<int>& B) {
	return iguales(A, A.begin(), B, B.begin());
}


/// Auxiliar
void copia_espejada(btree<int>& A, btree<int>::iterator itA) {
	btree<int> T;
	if(itA == A.end()) {
		return;
	} else {
		T.splice(T.begin(), itA.left());
		A.splice(itA.left(), itA.right());
		A.splice(itA.right(), T.begin());
		
		copia_espejada(A, itA.left());
		copia_espejada(A, itA.right());
	}
}

/// Wrapper
void copia_espejada(btree<int>& A) {
	copia_espejada(A, A.begin());
}


int main(int argc, char *argv[]) {
	btree<int> T1,T2;
	
//	lisp2btree("(1 (2 3 4) (6 7 .))", T1);
//	lisp2btree("(1 (2 5 4) (8 9 .))", T2);
	
//	btree2dot(T1,"a");
//	btree2dot(T2,"b");

//	cout<<"Son semejantes?: "<<semejantes(T1,T2)<<endl;
	
//	lisp2btree("(1 (2 3 4) (6 7 .))", T1);
//	lisp2btree("(1 (8 . 9) (2 5 4))", T2);
//	
//	cout<<"Son espejados?: "<<espejados(T1,T2)<<endl;
	
//	lisp2btree("(1 (2 . 4) (6 7 .))", T1);
//	lisp2btree("(1 (2 . 4) (6 7 .))", T2);
//	
//	cout<<"Son semejantes?: "<<semejantes(T1,T2)<<endl;
//	cout<<"Son iguales?: "<<iguales(T1,T2)<<endl;
//	
//	btree2dot(T1,"a");
//	btree2dot(T2,"b");
	
	lisp2btree("(1 (2 4 .) (6 (7 . 5) .))", T1);
	
	btree2dot(T1,"orignal");
	
	copia_espejada(T1);
	
	btree2dot(T1,"espejado");
	
	return 0;
}
