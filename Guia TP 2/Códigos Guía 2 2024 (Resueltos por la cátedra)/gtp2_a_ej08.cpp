#include <iostream>
#include <list>
#include <vector>

using namespace std;

void show_list(list<int>& L){
	cout<<"(";
	for(auto it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}
	

void ascendente2(list<int> &L, vector<list<int>> &VL){
	if(L.empty()) return;	
	list<int>::iterator it = L.begin();
	list<int>::iterator itIni = it;
	it++;
	while(it!=L.end()){
		list<int>::iterator itprev = prev(it);
		if(*it>=*itprev){
			it++;
		}else{
			list<int> sublista(itIni,it);
			VL.push_back(sublista);
			itIni = it;
			it++;
		}
	}
	
	if(itIni!=it){
		list<int> sublista(itIni,it);
		VL.push_back(sublista);		
	}
}
	
	
	int main() {
		list<int> L = {1, 2, 3, 2, 4, 7, 7, 5, 6, 8};
		//LL = {{1, 2, 3},{2, 4, 7, 7},{5,6,9}};
		list<list<int>> LL;
		vector<list<int>> VL;
		
		ascendente2(L,VL);
		
		
		cout<<endl<<"Ascendente con vector de listas: "<<endl;
		for(auto lista:VL){
			show_list(lista);
		}
		
		return 0;
	}
	
	
