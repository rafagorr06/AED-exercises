#include <iostream>
using namespace std;

template<typename T>
bool cubre_todo(vector< set<T> > &v, set<T>& W){
	
	for(auto &s : v){
		set<T> interseccion;
		set_intersection(W, s, interseccion);
		if( interseccion.size() != s.size() ) return false;
	}
	
	return true;
}
	
int main() {
	vector< set<int> > v = {
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5},
		{6, 7, 8}
		};
		
	set<int> W = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		
	if( cubre_todo(v, W) ) cout << "Cubre todo.";
	else cout << "No cubre todo.";
		
	return 0;
}








