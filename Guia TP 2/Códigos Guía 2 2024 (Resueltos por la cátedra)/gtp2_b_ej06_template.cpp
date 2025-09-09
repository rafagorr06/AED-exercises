#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void show_stack(stack<int> S){
	while(!S.empty()){
		cout<<S.top()<<endl;
		S.pop();
	}
}

int busca_mayor(stack<int> S, int n){

}

void invertir(stack<int>& S, int n){

}


void pancake_sort(stack<int>&S){

}

int main() {
	stack<int> S({5,32,56,4,-4,-6,-7,9});
	
	show_stack(S);	
	pancake_sort(S);
	cout<<endl;
	show_stack(S);	
	
	return 0;
}

