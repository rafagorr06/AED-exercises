#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>

using namespace std;
using namespace aed;

/// escribir una funcion que convierte un arbol ordenado en uno binario
/// si falta un hijo en AB se indica con -1 
void ord2bin(tree<int> &T, btree<int> &B, tree<int>::iterator itT, btree<int>::iterator itB)
{
	if (itT == T.end() or *itT == -1) 
	{
		return;
	}
	itB = B.insert(itB,*itT);
	itT = itT.lchild();
	ord2bin(T, B, itT, itB.left());
	if (itT != T.end())
	{
	itT++;
	ord2bin(T, B, itT, itB.right());
	}
}

void ord2bin(tree<int> &T, btree<int> &B)
{
	tree<int>::iterator itT = T.begin(); 
	btree<int>::iterator itB = B.begin();
	ord2bin(T, B, itT, itB);
}


int main() {
	btree<int> B;
	tree<int> T;

	
	lisp2tree("(1 (2 (3 -1 -1) (4 -1 -1))(5 -1 (6 -1 -1))",T);
	ord2bin(T,B);
	
	btree2dot(B,"binario");
	tree2dot(T,"aoo");
	return 0;
}








