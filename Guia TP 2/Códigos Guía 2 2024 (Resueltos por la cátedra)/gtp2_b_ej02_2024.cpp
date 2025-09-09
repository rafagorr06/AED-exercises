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

bool inverso(list<char> z){
		stack<char> p;
		queue<char> c;
		for(auto it = z.begin() ; it != z.end(); ++it){
			p.push(*it);
			c.push(*it);
		}
		while(!p.empty()){
			if(p.top() == c.front()){
				p.pop();
				c.pop();
			}else{
				return false;
			}
		}
		return true;
	}


		
//	
//bool inverso(list<char>&z)
//{
//	/// volcar z una pila y una cola
//	queue Q;
//	stack S;
//	
//	for(char c : z)
//	{		
//		/// chequear/eliminar espacios
//		Q.push(c);
//		S.push(c);
//	}
//	
//	/// comparar elemento a elemento
//	while (!Q.empty())
//	{
//		if (Q.front() != S.top())
//			return false;
//		Q.pop();
//		S.pop();
//	}
//	
//	return true;
//}

int main() {
	list<char> z = {'a','b','c','c','b','a'};				
	cout << inverso(z)
	return 0;
}







