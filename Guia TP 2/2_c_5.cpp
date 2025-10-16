#include <iostream>
#include <map>
#include <list>
#include <iterator>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void cutoffmap(map<int, list<int>> &M, int p, int q){
	map<int,list<int>>::iterator it=M.begin();
	while(it!=M.end()){
		if(p>(it->first)||q<=(it->first))
			it=M.erase(it);
		else{
			list<int>::iterator IT=(it->second).begin();
			int x=0;
			while (IT != (it->second).end()) {
				if (*IT >= p && *IT < q) 
					IT++;
				else
					IT=(it->second).erase(IT);
				x++;
			}
			if((it->second).empty())
										  it=M.erase(it);
			else
				it++;
		}
	}
}


int main() {
	graph2dot();
	return 0;
}







