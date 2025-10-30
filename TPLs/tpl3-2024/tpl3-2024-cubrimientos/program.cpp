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
// Nombre: Rafael gorrochategui
int DNI=98765432;

void set_union(set<int> &A, set<int> &B, set<int> &U){
  U = A;
  for (auto j:B) U.insert(U.end(),j);
}
  
  void multi_union(list<set<int>> &L, set<int> &U){
    for (auto i:L)
    {
      set<int> tmp;
      set_union(U,i,tmp);
      U = tmp;
    }
  }
    
    void conjunto_potencia(list<set<int>> &conjunto,list<set<int>> &L) {
      L.push_back({});
      list<set<int>> tmp;
      for (set<int> elemento:conjunto) {
        tmp.clear();
        for (auto i:L) {
          set<int> nuevo_subconjunto;
          set_union(i, elemento, nuevo_subconjunto);
          tmp.push_back(nuevo_subconjunto);
        }
        for (auto i:tmp) {
          L.push_back(i);
        }
      }
    }
    
    
    int cubrimientos(list<set<int>> &L) {
      int nsel = 0;
      set<int> universal;
      multi_union(L,universal);
      list<set<int>> P;
      conjunto_potencia(L, P);
      for (auto p:P) {
        if (universal.size() == p.size()) nsel++; 
      }
      return nsel;
    }

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(cubrimientos,vrbs);
  return 0;
}
