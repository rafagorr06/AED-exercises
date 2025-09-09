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

void merge(list<int> &L1, list<int> &L2, list<int> &L){	
}
	

void mergesort(list<int> &L)
	{		
	}
	
int main() {
	list<int> L = {1,3,6,11,2,4,6,10};
	
	mergesort(L);
	
	cout<<endl<<"Merge_sort: "<<endl;
	show_list(L);		
	
	return 0;
}
