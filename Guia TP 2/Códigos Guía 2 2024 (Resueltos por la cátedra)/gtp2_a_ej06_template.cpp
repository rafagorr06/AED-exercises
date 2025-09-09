#include <iostream>
#include <list>
using namespace std;


template<class T>
void show_list(list<T>& L){
	cout<<"(";
	for(typename list<T>::iterator it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")";
}

	void reemplazaJA(list<int> &L, list<int>& SEQ,list<int> &REEMP){
		auto it = L.begin();
		while(it!=L.end()){
			if(*it==*SEQ.begin()){
				int cont=1;
				auto it_ini = it;
				for(auto it_seq = next(SEQ.begin()); (it_seq!=SEQ.end() and it!=L.end()); it_seq++){
					it++;
					if(*it==*it_seq) cont++;
				}
				if(cont==SEQ.size()){
					it++;
					L.erase(it_ini,it);
					L.insert(it,REEMP.begin(), REEMP.end());					
					it--;
				}
				else it = it_ini;
			}			
			it++;
		}
	}
	
		
	void reemplazaJM(list<int> &L, list<int> &SEQ, list<int> &REEMP){
		for(auto it = L.begin(); it!=L.end(); it++){
			if(*it== *(SEQ.begin())){
				auto it_seq = ++(SEQ.begin());
				auto it_aux = ++it;
				while(*it_aux == *it_seq and it_seq!=SEQ.end()){
					it_aux++;
					it_seq++;
				}
				if(it_seq==SEQ.end()){
					it_aux=it;
					it++;
					L.erase(it_aux,next(it,SEQ.size()-1));
					L.insert(--it,REEMP.begin(),REEMP.end());
				}
			}
			
		}				
	}
		
		
	
void reemplazaAM(list<int> &L, list<int>& SEQ, list<int> &REEMP){		
		
		auto it1=L.begin();
		auto it2=SEQ.begin();
		
		int cont=0;		
		
		auto primero = L.begin();
		auto ultimo = L.begin();
		
		while(it1 != L.end()){
					
			if(*it1 == *it2){
				if (cont == 0) {
					primero = it1;
				}
				
				cont++;
				it2++;
				
				
				if(cont==SEQ.size()){					
					L.erase(primero,next(it1));
					L.insert(primero,REEMP.begin(),REEMP.end());
					cont = 0;
					it2 = SEQ.begin();
				}
			}
			it1++;
		}
	}	

		
void reemplazaMG( list<int> &L, list<int> &SEQ, list<int> &REEMP){
	auto itL = L.begin();
	auto itSEQ = SEQ.begin();
	auto itREEMP = REEMP.begin();
	
	while(itL != L.end()){
		if(*itL == *itSEQ){
			auto itL2 = itL;
			auto itSEQ2 = itSEQ;
			
			while(itSEQ2 != SEQ.end() && itL2 != L.end() && *itL2 == *itSEQ2){
				itL2++;
				itSEQ2++;
			}
			
			if(itSEQ2 == SEQ.end()){
				itL = L.erase(itL, itL2);
				itL = L.insert(itL, REEMP.begin(), REEMP.end());				
				/// incrementar itL por la longitud de reemp
				advance(itL, REEMP.size());
				//itSEQ = SEQ.begin(); 
			}			
		}
		itL++;
	}
}
//
//void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP)
//{
//	list<int>::iterator itL = L.begin();
//	list<int>::iterator itS = SEQ.begin();
//	list<int>::iterator itIni = L.begin();
//	
//	while itL! = L.end()
//	{
//		itIni = itL;
//		
//		while (itS != SEQ.end())
//		{
//			if (*itS == *itL)
//			{
//				/// mientras coincidan los elementos de la secuencia
//				/// avanzo en ambas listas
//				itS++;				
//				itL++;
//			}
//			else 
//			{
//				/// si no coinciden, vuelvo al principio de seq
//				/// y sigo avanzando en L
//				itS = SEQ.begin();				
//				itL++;
//			}
//			
//		}
//		
//		
//	}
//}
	
	void reemplazaVA(list<int> &L, list<int> &SEQ, list<int> &REEMP){
		
		list<int>::iterator itL = L.begin();
		list<int>::iterator itS = SEQ.begin();
		list<int>::iterator itIni = L.begin();
		
		while (itIni != L.end()){
			while (*itL == *itS){
				
				if (itS == SEQ.end()){
					list<int>::iterator itPos = L.erase(prev(itIni)++, prev(itL));
					list<int>::iterator itReemp = REEMP.begin();
					for (int i = 0; i<REEMP.size(); ++i){
						
						L.insert(itPos, *itReemp);
						itReemp++;
					}
					//itL = prev(itPos)++;
					//itS = SEQ.begin();
					
					itL = itPos;
					itIni = itPos;
					itS = SEQ.begin();
					break;
				}
				cout<<*itL<<endl;
				itS++;
				itL++;
			}
			itL++;
			itIni++;
		}
		
	}

void reemplazaPG(list<int> &L, list<int>& SEQ, list<int> &REEMP){	
			auto it_l = L.begin();
			auto it_seq = SEQ.begin();
			while (it_l != L.end()){
				int cont = 0;
				while(it_seq != SEQ.end()){
					if(*it_l == *it_seq){
						it_seq++;
						cont++;
					}else{
						it_seq = SEQ.begin();
						cont = 0;
					}
					it_l++;
				}
				if (it_seq == SEQ.end()){
					auto it_fin = it_l;
					advance(it_l,-cont);
					auto it_ini = it_l;
					it_l = L.erase(it_ini,it_fin);
					it_l = L.insert(it_l,REEMP.begin(),REEMP.end());
					it_seq = SEQ.begin();
				}
				it_l++;
			}
		}		
		
int main() {
					
	list<int> L = {1,2,3,4,5,1,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> SEQ = {4,5,1};
	list<int> REEMP = {9,7,3};
	show_list(L);
	reemplazaJA(L, SEQ, REEMP);	
	show_list(L);
	return 0;
}
			
			
