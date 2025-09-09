#include <list>
#include <iostream>

using namespace std;

void show_list(list<int> &L)
{
	for (auto x : L)
	{
		cout << x <<", ";
	}
	cout << endl;
}

void basic_sort(list<int> &L) 
{	
	list<int> L2;
		
	while (!L.empty())
	{
		list<int>::iterator it = L.begin() ;
		list<int>::iterator it_min = it;
		
		while (it != L.end())
		{		
			if (*it < *it_min) 
			{
				it_min = it;				
			}	
			it++;			
		}
		L2.push_back(*it_min);		
		L.erase(it_min);		
	}
	L2.swap(L);
}

int main(void){
	list<int> L = {4,2,6,1,3,5};
	show_list(L);
	
	basic_sort(L);
	show_list(L);
	
}
