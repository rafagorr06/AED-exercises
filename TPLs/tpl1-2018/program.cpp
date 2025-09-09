#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

#include <list>
#include <vector>
using namespace aed;
using namespace std;

int sign(int x){
  if(x>=0) return 1;
  else return -1;
}

void sign_split(list<int> &L,vector< list<int> > &VL) {
  list<int> aux;
  int s;
  
  for(auto it=L.begin();it!=L.end();it++){
    // solo si es el primer elemento
    if(it == L.begin()){
      s = sign(*it);
      aux.push_back(*it);
      continue;
    }
    // comparo el signo de los elementos
    if(sign(*it)==s){    // si es igual al signo que se esta usando por ahora, lo pusheo
      aux.push_back(*it);
    } else {    // sino, meto lista auxiliar, la borro, cambio signo y añado el elemento
      VL.push_back(aux);
      aux.clear();
      
      s = -s;
      aux.push_back(*it);
    }
  }
  if(!aux.empty()){
    VL.push_back(aux);
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void sign_join(vector< list<int> > &VL,list<int> &L) {
  int s = 1;
  
  while(!VL.empty()){
    
    for(auto itV=VL.begin();itV!=VL.end();) { 
      
      if(itV->empty()){
        itV = VL.erase(itV);
        if(itV == VL.end()) break;
        continue;
      }
      
      auto it = itV->begin();
      while(it != itV->end()) {
        if(sign(*it) == s) {
          L.push_back(*it);
          it = itV->erase(it);
        } else {
          break;
        }
      }
      ++itV;
    }
    s = -s;
  }
  
}
void insertalfinal(stack<int> &S,int n){
  if(S.empty()){
    S.push(n);
  }else{
    int top=S.top();
    S.pop();
    insertalfinal(S,n);
    S.push(top);
  }
}
void reverseStack(stack<int>&S){
  if(!S.empty()){
    int tope=S.top();
    S.pop();
    reverseStack(S);
    insertalfinal(S,tope);
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {

    ev.eval<1>(sign_split,vrbs);
    h1 = ev.evalr<1>(sign_split,seed,vrbs);

    ev.eval<2>(sign_join,vrbs);
    h2 = ev.evalr<2>(sign_join,seed,vrbs);

    ev.eval<3>(reverseStack,vrbs);
    h3 = ev.evalr<3>(reverseStack,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
