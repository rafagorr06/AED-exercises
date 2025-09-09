#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")"<<endl;
}

void compacta(list<int> &L,list<int> &S) {
	
}

int main(int argc, char *argv[]) {
	
	list<int> L = {1,3,6,2,8,2,3,2,3,10,1,4,5,7,6,4,7,2,3,7};
	list<int> S = {3,3,3,3};
	show_list(L);
	show_list(S);
	compacta(L,S);	
	show_list(L);
	return 0;
}





