#include <iostream>
#include <map>
#include <list>
#include <climits>
using namespace std;

typedef map<char,map<char,int>> graphW;
const int inf = INT_MAX;

int Dijkstra(graphW& G, 
			 char ini, 
			 char fin, 
			 list<char>& path){

}

int main() {
	
	graphW G2 = {
		{'A',{
			{'B',2},
		{'C',3},
		}},
	{'B',{
		{'A',2},
	{'D',5},
		{'E',2}
	}},
		{'C',{
			{'A',3},
		{'E',5}
		}},
	{'D',{
		{'B',5},
	{'E',1},
		{'Z',2}
	}},
		{'E',{
			{'B',2},
		{'C',5},
			{'D',1},
		{'Z',4}
		}},
	{'Z',{
		{'D',2},
	{'E',4}
	}}
	}; 
	
	list<char> path;
	int W = Dijkstra(G2,'A','Z',path);
	
	cout<<" camino con peso: "<<W<<" ---> (";
	for(char x:path){
		cout<<x<<" ";
	}
	cout<<")"<<endl;
	
	return 0;
}







