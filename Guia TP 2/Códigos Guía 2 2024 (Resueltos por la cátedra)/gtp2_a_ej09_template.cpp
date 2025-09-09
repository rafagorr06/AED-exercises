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
			
bool menor(int x, int y){
	return x < y;
}

bool mayor(int x, int y){
	return x > y;
}
	
bool distance(int x,int y){
	return abs(x) < abs(y);
}

void ordena(list<int> &L, bool (*f)(int,int)){ 
	for(auto it=L.begin(); it!=L.end(); it++){
		for(auto it2=it; it2!=L.end(); it2++){
			if(f(*it2,*it)){
				int aux = *it;
				*it = *it2;
				*it2 = aux;
			}
		}
	}
	}
	
void ordena2(list<int> &L, bool (*f)(int,int)){
	list<int> list_aux;
	while(L.size()!=0){
		auto it = L.begin();
		auto orden = it;
			while(it!=L.end()){
				if(f(*it,*orden)){
					orden = it;
				}
				it++;
			}
			list_aux.push_back(*orden);
			L.erase(orden);
		}
	//L = list_aux;
	L.swap(list_aux);
	}
			
int main() {
			
	cout<<endl<<"Lista: "<<endl;
	list<int> L2 = {1, 2, 3, -2, 4, -7, 7, -5, 6, 9};
	show_list(L2);
	
	cout<<endl<<"Ordenamientos: (menor)"<<endl;
	ordena(L2,menor);
	show_list(L2);
	
	cout<<endl<<"Ordenamientos: (mayor)"<<endl;
	ordena(L2,mayor);
	show_list(L2);
	
	cout<<endl<<"Ordenamientos: (dist)"<<endl;
	ordena(L2,distance);
	show_list(L2);
	
	return 0;
}

