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

void cutoffmap(map<int, list<int>> &M, int p, int q)
{
}


int main(void)
{
	map<int,list<int>> M = {	{1,{2,3,4}},
								{5,{6,7,8}},
								{8,{4,5}},
								{3,{1,3,7}}};
	
	show_map(M);
	cutoffmap(M,1,6);
	show_map(M);
	
}
