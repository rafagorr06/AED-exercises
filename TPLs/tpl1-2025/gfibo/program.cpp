#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>

using namespace aed;
using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Rafael Gorrochategui
int DNI=47104952;

bool isfibo(list<int>&L , int M){
  auto pos = L.begin();
  for(int i = 0; i<M ; i++){
    ++pos;
  }
  for(auto it = pos ; it!=L.end(); ++it){
    int suma = 0;
    auto it_aux = it;
    for(int j = 0; j<M ; j++){
      suma += *(--it_aux);
    }
    if(*it!=suma){
      return false;
    }
  }
  return true;
}

void gfibo_seed(list<int> &L,int MM,list<int> &Lseed) {
  Lseed.clear();
  for(int M=1 ; M<=MM ; M++){
    if(isfibo(L,M)==true){
      auto iter = L.begin();
      for (int i = 0 ; i<M ; i++){
        Lseed.push_back(*iter);
        ++iter;
      }
      break;
    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=123;

  ev.eval<1>(gfibo_seed,vrbs);
  return 0;
}
