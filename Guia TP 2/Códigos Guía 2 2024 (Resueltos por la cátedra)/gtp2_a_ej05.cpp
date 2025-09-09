#include <iostream>
#include <list>
using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}


void junta(list<int> &L, int c){
	list<int>::iterator it = L.begin();
	while(it != L.end()){
		list<int>::iterator it2 = it;
		it = next(it);
		for(int i=1; (it!=L.end() and i<c); i++){
			*it2 += *it;
			it = next(it);
		}
		it = L.erase(next(it2),it);
	}
}
	



int main(int argc, char *argv[]) {
	int c = 3;
	
	list<int> L = {1,3,2,4,5,2,2,3,5,7,4,3,2,2};
	junta(L,c);
	show_list(L);
	cout<<endl;
	
	
	return 0;
}
