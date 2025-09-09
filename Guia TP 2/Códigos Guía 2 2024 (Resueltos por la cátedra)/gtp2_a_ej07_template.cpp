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
	
void show_list(list<list<int>>& LL){
		cout<<"(";
		for(auto it = LL.begin();it!=LL.end();it++){
			show_list(*it);
		}
		cout<<")"<<endl;
	}

	void ascendente1MG(list<int> &L, list<list<int>> &LL){
		list<int> sublista;
		auto it = L.begin();
		
		/// que pasa si L es vacía?
		if L.empty() return;
		
		sublista.push_back(*it);		
		it++;
		
		while(it != L.end()){
			if(*it > sublista.back()){
				sublista.push_back(*it);
			}else{
				LL.push_back(sublista);
				sublista.clear();
				sublista.push_back(*it);
			}
			it++;
		}
		LL.push_back(sublista);
	}
		
		
int main() {
	list<int> L = {4,4,1, 2, 3, 2, 4, 7, 7, 5, 6, 8};
	
	list<list<int>> LL;
	
	ascendente1(L,LL);
	
	cout<<endl<<"Ascendente con lista de listas: "<<endl;
	for(auto lista:LL){
		show_list(lista);
	}
	
	
	return 0;
}
