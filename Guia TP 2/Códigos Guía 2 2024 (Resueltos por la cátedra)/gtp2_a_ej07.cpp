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

void ascendente1(list<int> &L, list<list<int>> &LL){
	//Si la lista esta vacía, vuelve sin más.
	if(L.empty()) return;	
	
	//Definimos itIni que apuntara a la posición inicial de la sublista siguiente
	list<int>::iterator itIni = L.begin();	
	//Los iteradores it e itprev se utilizaran para ir comparando las celdas sucesivas
	list<int>::iterator it = itIni;	
	it++;
	list<int>::iterator itprev = prev(it);;
	
	//la condicion de salida sera cuando it alcanza la última posición
	while(it!=L.end()){	
		itprev = prev(it);
		
		//si la siguiente posición es ascendente avanzamos
		if(*it>=*itprev){
			it++;
		}
		
		//caso contrario, creamos la sublista y la incorporamos a LL
		//actualizamos la posición inicial de la siguiente lista
		else{
			list<int> sublista(itIni,it);
			LL.push_back(sublista);
			itIni = it;
			it++;
		}
	}
	
	//incorporamos la última lista cuando it alcanza el final
	list<int> sublista(itIni,it);
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