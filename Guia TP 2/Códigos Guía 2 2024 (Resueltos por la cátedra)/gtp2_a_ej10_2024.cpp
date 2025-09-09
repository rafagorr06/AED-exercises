#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

void show_list(list<string>& L) {
	cout<<"(";
	for(list<string>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

/// Problema de Josephus
list<string> josephus(list<string>& nombres, int n) {
	list<string> eliminados;
	list<string>::iterator it = nombres.begin();
	while(!nombres.empty()) {
		advance(it, (n%nombres.size())-1);
		eliminados.push_back(*it);
		it = nombres.erase(it);
	}
	return eliminados;
}

list<string> josephusJA(list<string>& nombres, int n){
	list<string> L;
	auto it = nombres.begin();
	
	while(!nombres.empty()){
		
		/// x es la parte entera de nombres.size()/n;
		/// 
		// if(nombres.size()/n>=1) int x = nombres.size()/n;
		//int n_aux = n - x;		
		//for(int i=0; i<n_aux; i++){
		
		for(int i=0; i<n%nombres.size(); i++){
			it++;
			if(it==nombres.end()) it=nombres.begin(); //si no se chequea al final y sale del for it=nombres.end() cuando se haga erase o push_back tenemos error
		}
		L.push_back(*it);
		it=nombres.erase(it);
		if(it==nombres.end()) it=nombres.begin(); //si quedamos en el ultimo elemento de la lista entonces erase podria devolvernos it=nombres.end()
		
	}
	return L;
}
	
	list<string> josephusMC(list<string>& nombres, int n){
		if(n>0){
			
			list<string>copia=nombres;
			list<string>eliminados={};
			
			auto it=copia.begin();
			int i=0;
			while(!copia.empty()){
				
				for(int i=0;i<n;i++){
					it++;
					if(it==copia.end()){
						it=copia.begin();
					}	
				}
				
				eliminados.push_back(*it);
				it=copia.erase(it);
				if(it==copia.end()){
					it=copia.begin();
				}	
				
				
			}
			return eliminados;
		}
	}

list<string> josephusJC(list<string>& nombres, int n) {
	auto it =nombres.begin();
	
	//hago una lista con los eliminados par aponer el orden
	list<string> eliminados;
	
	while(nombres.size()>1){
		for (int i = 0; i < n; i++)
		{
			++it;
			if(it==nombres.end()){
				//si la list de nombres llego al final y todavia faltan numero para llegar a n, mando el iterado al principio del list asi sigue contando
				it=nombres.begin();
				
			}
		}
		//elimino el soldado actual y paso al otro q sigue
		
		eliminados.push_back(*it);
		it=nombres.erase(it);//si no esta al final del array sigue el ciclo en el siguiente, pero veriicp si esta en el final por las didas
		if (it==nombres.end())
		{
			it=nombres.begin();
		}
		
		
	}
	//cuando quede uno, ese sera e elegido, lo coloco en eliminado, 
	eliminados.push_back(nombres.front());
	return eliminados;
}

int main(int argc, char *argv[]) {
	list<string> nombres = {"roberto", "maria", "juana", "pepe", "daniel", "rosa"};
	
	show_list(nombres);	
	
	list<string> resultado = josephusJC(nombres, 3);
	
	show_list(resultado);	
	
	return 0;
}





