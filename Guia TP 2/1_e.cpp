#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int>L = {1,3,4,2,5,6};
	
	list<int>::iterator p,q;
	p = L.begin();
	q = ++p;
	p = L.erase(q);
	p++;
	q = p;
	q++;
	cout<<"p="<<*p<<" ";
	cout<<"q="<<*q;
	return 0;
}







