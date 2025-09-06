#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

bool inverso(list<char> &z){
	int num=0;
	
	stack<char> pila_aux;
	queue<char> cola_aux;
	
	for(auto it=z.begin();it!=z.end();++it){
		if(*it != ' '){
			pila_aux.push(*it);
			cola_aux.push(*it);
			num++;
		}
	}
	
	if (num == 0) return true;
	if (num % 2 !=0) return false;
	
	for(int i=0;i<num/2;i++){
		if(!(pila_aux.top()==cola_aux.front()))return false;
		pila_aux.pop();
		cola_aux.pop();
	}
	return true;
}
	
int main() {
	cout << boolalpha;
	
	list<char> a={'a','b','c','c','b','a'};
	cout<<inverso(a)<<endl;
	
	a={'a','b','c',' ','c','b','a'};
	cout<<inverso(a)<<endl;
	
	a={'a','b','c','d','e','f',};
	cout<<inverso(a)<<endl;
	
	a={'a','b','c','d','c','b','a'};
	cout<<inverso(a)<<endl;
	return 0;
}

