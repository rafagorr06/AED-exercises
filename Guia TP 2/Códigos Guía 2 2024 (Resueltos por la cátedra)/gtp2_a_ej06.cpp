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

		void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP){
			list<int>::iterator it = L.begin();
			list<int>::iterator itSEQ = SEQ.begin();
			while(it!=L.end()){
				list<int>::iterator itIni = it;
				while(itSEQ != SEQ.end() && it!=L.end()){
					if(*it==*itSEQ){
						itSEQ++;
						it++;
					}else{
						itSEQ = SEQ.begin();
						it++;
						itIni = it;
					}	
				}
				if(itSEQ==SEQ.end()){
					it = L.erase(itIni,it);
					it = L.insert(it,REEMP.begin(), REEMP.end());
					advance(it,REEMP.size());
					itSEQ = SEQ.begin();
				}
			}	
		}
			
			int main() {
								
				list<int> L = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
				list<int> SEQ = {4,5,1};
				list<int> REEMP = {9,7,3};
				reemplaza(L, SEQ, REEMP);
				
				show_list(L);
				return 0;
			}
			
			
