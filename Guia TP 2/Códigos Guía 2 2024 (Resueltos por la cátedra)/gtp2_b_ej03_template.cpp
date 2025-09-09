#include <iostream>
#include <list>


#include <string> 
#include <queue>
#include <stack>
using namespace std;

void show_stack(stack<int> S){
	while(!S.empty()){
		cout<<S.top()<< ', ';
		S.pop();
	}
	cout <<endl;
}

bool chequeo(list<char>&z)
{
	return false;
}

int main() {
	std::string str = "((a - b)*(5 - c))/4 "; 
	std::list<char> z; 
	
	for (char c : str) { 
		z.push_back(c); 
	} 
		
	cout << chequeo(z);
	return 0;
}







