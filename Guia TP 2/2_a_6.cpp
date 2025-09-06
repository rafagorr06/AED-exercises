#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

bool coincidencia(list<int>::iterator it, list<int>::iterator final, list<int>&SEQ){	auto it_seq=SEQ.begin();	auto it_temp=it;		while(it_seq!=SEQ.end()&&it_temp!=final){		if(*it_temp!=*it_seq){return false;		}		++it_temp;		++it_seq;		}			return it_seq==SEQ.end();}void reemplaza(list<int>&L, list<int>&SEQ, list<int>&REEMP){	if(SEQ.empty()) {
		return;
	}
	auto it=L.begin();	while(it!=L.end()){	if(coincidencia(it, L.end(), SEQ)){		auto it_next=it;		for(int i=0;i<SEQ.size();++i){++it_next;}			it=L.erase(it, it_next);			it=L.insert(it, REEMP.begin(), REEMP.end());			advance(it, REEMP.size());			} else{++it;}		}	}
	
int main() {
	list<int>L= {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int>SEQ= {4,5,1};
	list<int>REEMP= {9,7,3};
	
	reemplaza(L,SEQ,REEMP);
	
	for(int i=0, i<L.size(), i++) {
		cout<<L[i]<<endl;
	};
	return 0;
}







