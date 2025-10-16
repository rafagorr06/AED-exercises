#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>

using namespace aed;
using namespace std;

int height (btree<int>& A, btree<int>::iterator itA)
{
	int heightL, heightR;
	if (itA == A.end()) return 0;
	else 
		{
		heightL = height(A,itA.left());
		heightR = height(A,itA.right());
		}
	
	return(max(heightL,heightR)+1);
}

bool is_balanced(btree<int>& A, btree<int>::iterator itA) {	
	if (itA == A.end()) return true;
	
	if (abs(height(A,itA.left())-height(A,itA.right()))>1) return false;
	
	return (is_balanced(A,itA.left()) and is_balanced(A,itA.right()));
}

bool is_balanced(btree<int>& A)
{
	return is_balanced(A, A.begin());
}
int main() {
	
	btree<int> BT;
	
	//	lisp2btree("(4 (9 4 6) (7 2 3))", BT1);
	//	lisp2btree("(4 (9 4 6) (8 3 4))", BT2);
	//	
	//	btree2dot(BT1, "BT1");
	//	btree2dot(BT2, "BT2");
	//	
	
	lisp2btree("(4 (9 . 8) (5 7 8))", BT);
	//lisp2btree("(4 (9 . 8) (5 7 (8 (5 5 .) .)))", BT);
	
	btree2dot(BT, "BT");
	
	cout<<"Altura? "<<height(BT, BT.begin())<<endl;
	cout<<"Is balanced? "<<is_balanced(BT)<<endl;
	
	return 0;
}

�