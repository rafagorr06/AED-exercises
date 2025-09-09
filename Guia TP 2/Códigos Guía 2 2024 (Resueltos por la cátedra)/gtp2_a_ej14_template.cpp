#include <iostream>
#include <list>

using namespace std;

void show_list(list<int>& L){
	cout<<"(";
	for(auto it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}

void merge(list<int> &L1, list<int> &L2, list<int>& L) {		
	}
	
	
int main() {
	list<int> L1 = {1,3,6,11};
	list<int> L2 = {2,4,6,10};
	
	list<int> L;
	
	merge(L1,L2,L);
	
	cout<<endl<<"Union de listas ordenadas: "<<endl;
	show_list(L);		
	
	return 0;
}
