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


void merge(list<int> &L1, list<int> &L2, list<int>& L) {	

}

void merge_map(map<int,list<int>> &A, map<int,list<int>> &B, map<int,list<int>> &C)
{
}

int main(void)
{
	map<int,list<int>> M1 = {	{1,list<int> {2,3,4}},
								{2,list<int> {3,4,5}}};
	map<int,list<int>> M2 = {	{1,list<int> {3,4,5}},
								{2,list<int> {4,5,6}}};
	
	map<int,list<int>> M3;
	
		
	show_map(M1);
	show_map(M2);
	
	merge_map(M1,M2,M3);
	show_map(M3);	
}
