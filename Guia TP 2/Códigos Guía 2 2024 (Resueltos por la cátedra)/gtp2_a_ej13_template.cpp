#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")"<<endl;
}

int sumlist(list<int>::iterator itL, list<int>::iterator itR){
	int sum = 0;
	
	while (itL != itR) {
		sum += *itL;
		itL++;
	}			
	return sum;
}

list<int> max_sublist(list<int> &L){

}

int main(int argc, char *argv[]) {
	
	list<int> L1 = {1,2,-5,4,-3,2};
	list<int> L2 = {5,-3,-5,1,7,-2}; 
	list<int> L3 = {4,-3,11,-2};
		
	list <int> L = L1;	
	show_list(L);
	
	list<int> ML = max_sublist(L);
	show_list(ML);
	return 0;
}
