#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>

using namespace std;
using namespace aed;

/// escribir una funcion que convierte un arbol binario en uno ordenado
/// si falta un hijo, reemplazar por -1 en el AOO

void bin2ord(btree<int> &B, tree<int> &T, btree<int>::iterator itB, tree<int>::iterator itT)
{
	if (itB == B.end()) 
	{
		itT = T.insert(itT, -1);
		return;
	}
	else 
	{
		itT = T.insert(itT, *itB);
	}
	bin2ord(B, T, itB.right(), itT.lchild());
	bin2ord(B, T, itB.left(),  itT.lchild());	
}

void bin2ord(btree<int> &B, tree<int> &T)
{
	btree<int>::iterator itB = B.begin();
	tree<int>::iterator itT  = T.begin();
	bin2ord(B, T, itB, itT);
}

int main() {
	btree<int> B;
	tree<int> T;
	lisp2btree("(1 (2 3 4)(5 6 .))",B);
	bin2ord(B,T);
	btree2dot(B,"binario");
	tree2dot(T,"aoo");
	return 0;
}








