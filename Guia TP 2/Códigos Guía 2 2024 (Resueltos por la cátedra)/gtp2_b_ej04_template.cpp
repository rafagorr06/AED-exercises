#include<iostream>
#include <list>
#include <stack>
using namespace std;

void show_list(list<int>& L){
	cout<<"(";
	for(auto it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}
	
void sort(list<int> &L)	
{
	
}
	
	
	int main() {
		list<int> L({5,4,3,2,1});						
		show_list(L);
		
		sort(L);
		show_list(L);
		
	}
	
