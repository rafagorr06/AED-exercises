#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

void show_stack(stack<int> S){
	while(!S.empty()){
		cout<<S.top()<< ', ';
		S.pop();
	}
	cout <<endl;
}

bool inverso(list<char>&z)
{
	return false;
}

int main() {
	list<char> z = {'a','b','c','c','b','a'};				
	cout << inverso(z)
	return 0;
}







