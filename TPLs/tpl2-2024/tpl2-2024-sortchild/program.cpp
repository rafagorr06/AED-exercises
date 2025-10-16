#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace aed;
using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Rafael Gorrochategui

int DNI=98765432;

void sortchild(tree<int> &T,tree<int>::iterator nt,tree<int> &Q,tree<int>::iterator nq) {
  auto ct = nt.lchild();
  while (ct != T.end()){
    //copy en ct
    auto cq = nq.lchild();
    while(cq!=Q.end() && *cq<=*ct) cq++;
    cq = Q.insert(cq,*ct);
    sortchild(T,ct,Q,cq);
    ct++;
  }
}

void sortchild(tree<int> &T,tree<int> &Q) {
  if (T.empty()) return;
  auto nt = T.begin();
  auto nq = Q.begin();
  nq = Q.insert(nq,*nt);
  sortchild(T,nt,Q,nq);
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(sortchild,vrbs);
  return 0;
}
