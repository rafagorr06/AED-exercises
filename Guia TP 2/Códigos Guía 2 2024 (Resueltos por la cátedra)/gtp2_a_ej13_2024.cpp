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
	auto itL = L.begin();
	auto itR = L.begin();
	
	auto itL_max = L.begin();
	auto itR_max = L.begin();
	
	int max_sum = -100000;
	
	while (itL != L.end())
	{
		itR = itL;
		
		while (itR != L.end())
		{
			int parcial = sumlist(itL, itR);
			
			if (parcial > max_sum) 
			{
				max_sum = parcial;
				itL_max = itL;
				itR_max = itR;
			}
			
			itR++;
		}		
		itL++;
	}
	
	list<int> L2;
	L2.splice(L2.begin(),L,itL_max,itR_max);
	return L2;
}
	
	list<int> max_sublist_for(list<int> &L){	
		
		auto itL_max = L.begin();
		auto itR_max = L.begin();
		
		int max_sum = -100000;
		
		for (auto itL = L.begin();itL != L.end();itL++)
		{	
			if (*itL >= 0 ){
				for (auto itR = itL ;itR != L.end(); itR++)
				{
					if (*itR >=0 )
					{
						int parcial = sumlist(itL, itR);
						
						if (parcial > max_sum) 
						{
							max_sum = parcial;
							itL_max = itL;
							itR_max = itR;
						}
					}
									
				}				
			}	
		}
		
		list<int> L2;
		L2.splice(L2.begin(),L,itL_max,itR_max);
		return L2;
	}

	list<int> max_sublistMG(list<int> &L) {
			list<int> Lmax;
			int max = -999999;
			
			for (auto i = L.begin(); i != L.end(); i++) {
				if(*i>0){
					int sum = 0;
					list<int> Ltemp;
					for (auto j = i; j != L.end(); j++) {
						sum += *j;
						Ltemp.push_back(*j);
						if (sum > max) {
							max = sum;
							Lmax = Ltemp;
						}
					}
				}
			}
			return Lmax;
		}		

	list<int> max_sublistNE(list<int> &L){
		
		auto itL = L.begin();
		auto itR = L.begin();
		auto itL_max = L.begin();
		auto itR_max = L.begin();
		
		int max_sum = -99999;
		
		while (itL != L.end()){
			itR = itL;
			if (*itL < 0){itL++;}else{
				if (*itR < 0){itR++;}else{
					while (itR != L.end()){
						int parcial = sumlist(itL,itR);
						if (parcial > max_sum){
							max_sum = parcial;
							itL_max = itL;
							itR_max = itR;
						}
						itR++;
					}
				}
				itL++;
			}			
		}
		
		list<int> L2;
		L2.splice(L2.begin(),L,itL_max,itR_max);
		return L2;
	}	
	
int main(int argc, char *argv[]) {
	
	list<int> L1 = {1,2,-5,4,-3,2};
	list<int> L2 = {5,-3,-5,1,7,-2}; 
	list<int> L3 = {4,-3,11,-2};
		
	list <int> L = L2;	
	show_list(L);
	
	list<int> ML = max_sublistNE(L);
	show_list(ML);
	return 0;
}
