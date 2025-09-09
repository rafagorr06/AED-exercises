#include<iostream>
#include <list>
#include <queue>
using namespace std;

void show_list(list<int>& L){
	cout<<"(";
	for(auto it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}

	
void sortQueue(list<int> &L){
		list<int>::iterator it1,it2;
		queue<int> c;
		
		while(!L.empty()){
			it1 = L.begin();
			it2 = next(it1);
			
			while(it2 != L.end()){
				if(*it2 < *it1){
					it1 = it2;
				}
				++it2;
			}
			c.push(*it1);
			L.erase(it1);
//			it1 = L.erase(it1);
//			it2 = next(it1);
		}
		
		while(!c.empty()){
			L.push_back(c.front());
			c.pop();
		}
		
	}	
	
	int main() {
		list<int> L({5,4,3,2,1});						
		show_list(L);
		
		sort(L);
		show_list(L);
		
	}
	
