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

bool areinverse(map<int,int> &M1, map<int,int> &M2) {

}


int main(void)
{
	map<int,int> M1 = {{1,2},{2,3},	{3,4},{4,5},{7,8}};
	//map<int,int> M2 = {{1,2},{2,3},	{3,4},{4,5},{7,8}};
	map<int,int> M2 = {{2,1},{3,2},{4,3},{5,4},{8,7}};
	show_map(M1);
	show_map(M2);
	
	cout<<"Son inversas? "<<areinverse(M1,M2);
	
}
