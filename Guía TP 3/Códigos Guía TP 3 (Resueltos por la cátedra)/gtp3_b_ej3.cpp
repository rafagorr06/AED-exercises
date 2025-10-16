#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>

using namespace std;
using namespace aed;

/// escribir una funcion que retorna el numero de nodos a profundidad prof o mayor

void cant_nodos_prof(btree<int> &A, int prof, btree<int>::iterator it, int curr_level, int &curr_count)
{
	if (it == A.end()) return;
	
	if (curr_level >= prof)
		curr_count++;
	
	cant_nodos_prof(A, prof, it.left(),  curr_level+1,curr_count);
	cant_nodos_prof(A, prof, it.right(), curr_level+1,curr_count);
}

int cant_nodos_prof(btree<int> &A, int prof)
{
	int count = 0;
	btree<int>::iterator it = A.begin();
	cant_nodos_prof(A, prof, it, 0,count);
	return count;
}

int main() {
	btree<int> A;
	lisp2btree("(1 (2 3 4)(5 6 .))",A);
	cout << cant_nodos_prof(A, 3);
	
	return 0;
}








