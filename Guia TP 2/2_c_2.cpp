#include <iostream>
#include <map>
#include <list>
using namespace std;
void show_map(map<int,int> &M)
{
	cout<<"M={"<<endl;
	for(typename map<int,int>::iterator it = M.begin(); it != M.end(); it++) {
		cout<<"["<<(*it).first<<"]="<<(*it).second<<endl;
	}
	cout<<"}"<<endl;
}

void show_list(list<int>& L) {
	cout<<"(";
	for(typename list<int>::iterator it = L.begin(); it != L.end(); it++) {
		cout<<*it<<" ";		
	}
	cout<<")"<<endl;
}

void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals) {
	auto it_v = Vals.begin();
	auto it_k = Keys.begin();
	
	while(it_k != Keys.end()){
		if(it_v != Vals.end()){
			M[*it_k]=*it_v;
		} else {
			M[*it_k] = 0;
		}
	}
}


int main(void)
{
	map<int,int> M;
	list<int> L1 = {1,2,3,4,7}, L2 = {2,3,4,5,8};
	
	show_list(L1);
	show_list(L2);
	
	list2map(M, L1, L2);
	show_map(M);
	
}
