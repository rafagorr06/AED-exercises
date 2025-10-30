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
int DNI=98765432;

void preorder(btree<int> &T,btree<int>::iterator it,list<int> &L) {
  if (it==T.end()) return;
  L.push_back(*it);
  preorder(T,it.left(),L);
  preorder(T,it.right(),L);
}

void abbpred(btree<int> &T,comp_t comp) {
  list<int> L;
  preorder(T, T.begin(),L);
  T.clear();
  for(auto i:L){
    auto it = T.begin();
    while (it!=T.end()) {
      if (comp(i,*it)){
        it = it.left();
      } else {
        it = it.right();
      }
    }
    T.insert(it,i);
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=1234;
  ev.eval<1>(abbpred,vrbs);
  // ev.evalr<1>(abbpred,seed,vrbs);
  return 0;
}
