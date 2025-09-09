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
		
/// RECIBE L1 y L2 ORDENADAS y las une EN ORDEN en L	
void merge(list<int> &L1, list<int> &L2, list<int>& L) {
	auto it1 = L1.begin();
	auto it2 = L2.begin();
	
	while(it1!=L1.end() and it2!=L2.end()){
		if(*it1<=*it2){
			L.push_back(*it1);
			it1++;
		}
		else if(*it2<*it1){
			L.push_back(*it2);
			it2++;
		}
	}
	///L.insert(L.end(),it1,L1.end());
	///L.insert(L.end(),it1,it1); -> no hace nada
	///L.insert(L.end(),it2,L2.end());
	
	while (it1!=L1.end()){
		L.push_back(*it1);
		it1++;
	}
	while (it2!=L2.end()){
		L.push_back(*it2);
		it2++;
	}	
	
	}

void mergesort(list<int> &L)
{
	list<int> L1, L2;
	auto itL = L.begin();
	
	if (L.size() > 1) {
		L1.splice(L1.begin(),L,L.begin());
		mergesort(L);
	}
	
	merge(L1,L,L2);
	L.swap(L2);	
}

	
int main() {
	//list<int> L1 = {1,3,6,11};
	//list<int> L2 = {2,4,6,10};
	
	list<int> L = {1,3,6,11,2,4,6,10};
	
	//merge(L1,L2,L);
	mergesort(L);
	cout<<endl<<"Union de listas ordenadas: "<<endl;
	show_list(L);		
	
	return 0;
}
