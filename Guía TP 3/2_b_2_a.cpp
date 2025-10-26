#include <iostream>
using namespace std;

void misma_estructura(btree<int> &t,btree<int>::iterator tn,btree<int> &q,btree<int>::iterator qn,bool &band){
	if(tn.left()!=t.end() and qn.left()!=q.end()){
		misma_estructura(t,tn.left(),q,qn.left(),band);
	}else if((tn.left()==t.end() and qn.left()!=q.end()) or (tn.left()!=t.end() and qn.left()==q.end())){
		band=false;
	}
	
	if(tn.right()!=t.end() and qn.right()!=q.end()){
		misma_estructura(t,tn.right(),q,qn.right(),band);
	}else if((tn.right()==t.end() and qn.right()!=q.end()) or (tn.right()!=t.end() and qn.right()==q.end())){
		band=false;
	}
}
	
	bool misma_estructura(btree<int> &t,btree<int> &q){
		bool band=true;
		if(t.begin()!=t.end() and q.begin()!=q.end()){
			misma_estructura(t,t.begin(),q,q.begin(),band);
		}else{
			return false;
		}
		return band;
	}

int main() {
	
	return 0;
}







