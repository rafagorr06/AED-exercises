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
	return x<y;
}

bool mayor(int x, int y){
	return x>y;
}
	
bool distance(int x,int y){
	return abs(x)<abs(y);
}
		
void ordena(list<int> &L, bool (*f)(int,int)){
	//utilizando una lista auxiliar L2,
	list<int> L2;
	
	while(!L.empty()){
		//tomar el siguiente elemento de L a ubicar,
		list<int>::iterator it = L.begin();
		list<int>::iterator itNext = L.begin();
		while(it!=L.end()){
			if(f(*it,*itNext)){
				itNext = it;
			}
			it++;
		}
		L2.push_back(*itNext);
		L.erase(itNext);
	}
	L.swap(L2);
	
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

