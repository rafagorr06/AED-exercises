#include <iostream>
using namespace std;

template<typename T>
void set_intersection(set<T> &a,set<T> &b,set<T> &c){
	c.clear();
	auto ita=a.begin();
	auto itb=b.begin();
	while(ita!=a.end() and itb != b.end()){
		if(*ita<*itb){
			//c.insert(c.end(),*ita);
			++ita;
		}else if(*itb<*ita){
			//c.insert(c.end(),*itb);
			++itb;
		}else{
			c.insert(c.end(),*ita);
			++ita;
			++itb;
		}
	}
}	

int main() {
//	
	return 0;
}







