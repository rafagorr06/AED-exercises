#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

typedef map<int,list<int>> graph;

int main() {
	graph G={
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
	map<int,list<int>> D = distancia(G);
	
	cout<<"Distancia a vertices: "<<endl;
	for(auto c : D){
		cout<<"( ";
		for(auto x : c){
			cout<<x<<" ";
		}
		cout<<")"<<endl;
	}
	return 0;
}







