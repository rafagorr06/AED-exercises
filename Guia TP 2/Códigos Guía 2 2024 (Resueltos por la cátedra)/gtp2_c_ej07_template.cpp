#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>

using namespace aed;
using namespace std;

void show_map(map<int,list<int>> &M)
{
	cout<<"M={"<<endl;
	for(typename map<int,list<int>>::iterator it = M.begin(); it != M.end(); it++) {
		cout<<"["<<(*it).first<<"]=";
		list<int>::iterator itList = (*it).second.begin();
			while (itList != (*it).second.end())
			{
				cout << *itList <<", ";		
				itList++;
			}
	}
	cout<<"}"<<endl;
}

void show_list(list<int>& L) {
	cout<<"(";
	for(typename list<int>::iterator it = L.begin(); it != L.end(); it++) {
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}



bool es_vecino(list<int>& L, int nodo) {
	return true;
}

bool es_camino(map<int,list<int>> G, list<int> &L) {
	/// es camino
	return true;
}


int main(void)
{	
	map<int, list<int>> G = {
		{1, {2,6}},
		{2, {1,3,4,5}},
		{3, {2,5,7}},
		{4, {2,6}},
		{5, {2,3}},
		{6, {1,4,7}},
		{7, {3,6}}
	};
	
	
	graph2dot(G);
	
	list<int> L = {1,2,3,5,3};
	
	cout<<"L es camino? "<< es_camino(G,L);
	
}
