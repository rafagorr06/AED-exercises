#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

void show_list(list<string>& L) {
	cout<<"(";
	for(list<string>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

/// Problema de Josephus
list<string> josephus(list<string>& nombres, int n) {
	
}


int main(int argc, char *argv[]) {
	list<string> nombres = {"roberto", "maria", "juana", "pepe", "daniel", "rosa"};
	
	list<string> resultado = josephus(nombres, 2);
	
	show_list(resultado);	
	
	return 0;
}





