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

void compactaJA(list<int> &L,list<int> &S){
	auto it_S = S.begin();
	auto it_L = L.begin();
	
	while(it_L!=L.end() and it_S!=S.end()){
		if(*it_S>0){
			int suma = 0;
			for(int i=0; i<*it_S and it_L!=L.end(); i++){
				suma = suma + *it_L;
				it_L = L.erase(it_L);
			}
			it_S = S.erase(it_S);
			it_L = L.insert(it_L,suma); 
			it_L++; //Estas dos lineas se pueden reemplazar por insert(it_L,suma) dado que el iterador it_L ya apunta a donde queremos 
		}
		else{
			++it_S;
		}
	}
}
	
void compactaMG(list<int> &L, list<int> &S) {
			auto it = S.begin();
			while(it!=S.end() and !L.empty()){
				int n = *it;
				if(n>0){
					int suma = 0;
					for(int i=0; i<n; i++){
						suma += L.front();
						L.pop_front();
					}				
					L.push_front(suma);
				}
				it++;
			}
		}

void compactaNE(list<int> &L, list<int> &S){
	auto it1 = L.begin();
	auto it2 = S.begin();
	//list<int>comp;
	while(it1!=L.end() && it2 != S.end()){
		int sum_h = *it2;
		int suma=0;
		for(int i=0;i<sum_h && it1!=L.end();i++) { 
			suma+=*it1;
			it1 = L.erase(it1);
			//it1++;
		}
		//comp.push_back(suma);
		it1 = L.insert(it1,suma); 
		it1++;
		it2++;
	}
//	L = comp;
}
	
	
void compacta(list<int> &L,list<int> &S) {
	
}

int main(int argc, char *argv[]) {
	
	list<int> L = {1,3,6,2,8,2,3,2,3,10,1,4,5,7,6,4,7,2,3,7};
	list<int> S = {3,3,3,3,20};	
	
	show_list(L);
	show_list(S);
	compactaNE(L,S);	
	show_list(L);
	return 0;
}





