#include <iostream>
#include <map>
#include <list>
using namespace std;

void show_map(map<int,list<int>> &M)
{
	cout<<"M={"<<endl;
	for(typename map<int,list<int>>::iterator it = M.begin(); it != M.end(); it++) {
		cout<<"["<<(*it).first<<"]=";
		list<int>::iterator itList = (*it).second.begin();
			while (itList != (*it).second.end())
			{
				cout << *itList <<", ";		
				itList++;
			}
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

void apply_map(list<int> &L, map<int,int> &M, list<int> &ML)
{
}


int main(void)
{
	list<int> L = {1,2,3,4,5,6,7,1,2,3};
	list<int> ML;
	map<int,int> M = {	{1,2},
								{2,3},
								{3,4},
								{4,5},
								{7,8}};
		
	apply_map(L,M,ML);	
	
	show_list(L);
	show_list(ML);
}
