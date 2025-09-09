#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;


list<list<int>> compConexas(map<int,list<int>>& G){
	list<list<int>> CC;

	return CC;
}
	
	int main() {		
		map<int,list<int>> G={
			{0,{1}},
		{1,{0,3,4}},
			{2,{3}},
		{3,{1,2}},
			{4,{1}},
		{5,{6}},
			{6,{5,7}},
		{7,{6}}
		};
		graph2dot(G);
		list<list<int>> CC = compConexas(G);
		
		cout<<"Componentes conexas: "<<endl;
		for(auto cc : CC){
			cout<<"( ";
			for(auto x : cc){
				cout<<x<<" ";
			}
			cout<<")"<<endl;
		}
		
		return 0;
	}
	
