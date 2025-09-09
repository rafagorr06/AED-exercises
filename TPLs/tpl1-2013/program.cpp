#include "Evaluar.hpp"

void split_mod(list<int>&L, int m, vector< list<int> >&VL) {
	
	VL.assign(m, {}); 
	for (int x : L) 
		VL[x % m].push_back(x);
}

bool is_sublist(list<int>&L1, list<int>&L2) {
	auto p1= L1.begin();
	auto p2=L2.begin();
	
	list<int>aux;
	while(p1!=L1.end()){
		if(*p1 == *p2){
			aux.push_back(*p1);
			++p1;
			++p2;
		} else {
			++p1;
		}
	}
	
	if(aux==L2){
		return true;
	} else {
		return false;
	}
}


void max_sublist(list<int>&L, list<int>&subl) {
  list<int>tmp;
  for(auto it = L.begin() ; it!=L.end() ; ++it){
	  if(*it % 2 == 0){
			tmp.push_back(*it);
	  } else {
		  tmp.clear();
	  }
	  if(tmp.size() > subl.size()){
		  subl = tmp;
	  }
  }
}

int main() {
  aed::Evaluar ev;
  ev.evaluar1(split_mod);
  ev.evaluar2(is_sublist);
  ev.evaluar3(max_sublist);
  return 0;
}
