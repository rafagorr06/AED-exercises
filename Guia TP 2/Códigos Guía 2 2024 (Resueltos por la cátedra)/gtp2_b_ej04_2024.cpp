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

void sort(list<int> &L){
		stack<int> S;
		
		while(!L.empty()){
			auto it = L.begin();
			auto it_save = next(it);
			while(it!=L.end()){
				if(*it<*it_save){
					it_save = it;
				}
				it++;
			}
			S.push(*it_save);
			L.erase(it_save);
		}
		
		while(!S.empty()){
			L.push_back(S.top());
			S.pop();
		}
	}	
	
void sortStack(list<int> &L){
		stack<int> p;
		list<int>::iterator it1,it2;
		
		
		while(!L.empty()){
			///ubica it1 en la posicion del menor valor en L
			it1 = L.begin();
			it2 = next(it1);
			while(it2 != L.end()){
				if(*it2 < *it1){
					it1 = it2;
				}
				++it2;
			}
			/// empila y elimina el menor valor
			p.push(*it1);
			L.erase(it1);
			//it1 = L.erase(it1);
			//it2 = next(it1);
		}
		
		///desempila
		while(!p.empty()){
			/// menor a mayor
			///L.push_front(p.top());
			
			/// mayor a menor
			L.push_back(p.top());
			p.pop();
		}
		
	}
	
	
	int main() {
		list<int> L({5,4,3,2,1});						
		show_list(L);
		
		sort(L);
		show_list(L);
		
	}
	
