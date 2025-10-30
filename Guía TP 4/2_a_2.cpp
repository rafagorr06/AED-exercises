#include <iostream>
using namespace std;

template<typename T>	
bool disjuntos(vector<set<T>>&v){
	set<T> c;
	c.clear();
	for(size_t i=0;i<v.size()-1;i++) { 
		for(size_t j=i+1;j<v.size();j++) {
			set_intersection(v[i],v[j],c);
			if(c.begin()!=c.end()){
				return false;
			}
		}
	}
	return true;
}
	

int main() {
	
	return 0;
}







