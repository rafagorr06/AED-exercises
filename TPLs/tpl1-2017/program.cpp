#define USECHRONO
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include "eval.hpp"

#include <list>
#include <iterator>
using namespace aed;
using namespace std;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void extract_range(list<int> &L1, list<int>::iterator p, list<int>::iterator q, list<int> &L2) {
  if(p==L1.end()) return;
  
  if(p==q) {
    L2.clear();
    return;
  }
  
  if(distance(L1.begin(),p) < distance(L1.begin(),q)){
    while(p!=q){
      L2.push_back(*p);
      p = L1.erase(p);
    }
  }
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int add_elements(list<int>& L, stack<int> &S) {
  int reps = 0;
  
  while(!S.empty()){
    int x = S.top();
    S.pop();
    bool inserted = false;
    
    for(auto it=L.begin();it!=L.end();it++){
      if(x<*it){
        it = L.insert(it,x);
        inserted = true;
        break;
      }
    }
    if(!inserted){
      L.push_back(x);
    }
    
  }
  
  for(auto it=L.begin();it!=prev(L.end());++it){
    if(*it == *next(it) && *prev(it)!=*it) reps++;
  }
  return reps;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void divisors(int x,list<int> &divs){
  for(int i=2;i<=x;i++){
    if(x%i==0) divs.push_back(i);
  }
}

bool coprimos(int x,int y){
  list<int> Lx, Ly;
  divisors(x,Lx); divisors(y,Ly);
  
  for(auto itx=Lx.begin();itx!=Lx.end();itx++){
    for(auto ity=Ly.begin();ity!=Ly.end();ity++){
      if(*ity==*itx) return false;
    }
  }
  return true;
}

bool coprimos(list<int>&L) {
  for(auto it=L.begin();it!=L.end();it++){
    for(auto it2=L.begin();it2!=L.end();it2++){
      if(it==it2) continue;
      
      if(!coprimos(*it,*it2)) return false;
    }
  }
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  ev.eval<1>(extract_range,vrbs);
  h1 = ev.evalr<1>(extract_range,seed,vrbs);
  
  ev.eval<2>(add_elements,vrbs);
  h2 = ev.evalr<2>(add_elements,seed,vrbs);
  
  ev.eval<3>(coprimos,vrbs);
  h3 = ev.evalr<3>(coprimos,seed,vrbs);

  printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
         seed,h1,h2,h3);
  
  return 0;
}
