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
	///si es '(', apilamos
	///si es ')', desempilamos
	/// si la pila queda vacía, todo OK
	/// si la pila esta vacia y ')', error
	/// si la pila no queda vacia, error
			
	stack<char>parentesis;

	for( list<char>::iterator it=z.begin(); it!=z.end(); ++it ) { 
		if (it* == '(')
			parentesis.push(*it);
		if (*it == ')')
			if (parentesis.empty())
				{
				return false;
			}
			else 
				{
				parentesis.pop();
				}
	}
	
		
	if(parentesis.empty())
		return true;		
	return false;
}

bool chequeo(list<char>&z){
	stack<char> par;
	auto it = z.begin();
	while (it==z.end()) {
		if(*it == '('){
			par.push(*it);
		} 
		if(*it == ')'){
			if(par.empty()) return false;
			par.pop();
		}
		it++;
	}
	if (par.empty()) return true;
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







