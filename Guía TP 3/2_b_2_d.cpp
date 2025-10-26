#include <iostream>
using namespace std;

void copia_espejada(btree<int> &t,btree<int>::iterator nt,btree<int> &q,btree<int>::iterator nq){
	nq=q.insert(nq,*nt);
	if(nt.left()!=t.end()){
		copia_espejada(t,nt.left(),q,nq.right());
	}
	
	if(nt.right()!=t.end()){
		copia_espejada(t,nt.right(),q,nq.left());
	}
}
	
void copia_espejada(btree<int> &t,btree<int> &q){
	if(t.begin()!=t.end()){
		copia_espejada(t,t.begin(),q,q.begin());
	}
}

int main() {
	
	return 0;
}







