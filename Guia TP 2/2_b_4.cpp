#include <iostream>
using namespace std;

void SortStack(list<int> &L){
	if(L.empty()){
	} else {
		stack<int>Aux;
		while(!(L.empty())){
			auto itmenor=L.begin();
			for(auto it=L.begin();it!=L.end();it++){
				if(*itmenor>*it){
					itmenor=it;
				}
			}
			Aux.push(*itmenor);
			L.erase(itmenor);
		}	
		while(!Aux.empty()){
			L.push_back(Aux.top());
			Aux.pop();
		}
	}
}

int main() {
	
	return 0;
}







