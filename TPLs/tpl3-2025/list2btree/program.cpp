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

const int INT=-1,HOJ=-2,LAM=-3;

void construccion(list<int> &lista, btree<int> &arbol, btree<int>::iterator pos) {
  int tipo = lista.front();
  lista.pop_front();
  int valor = lista.front();
  lista.pop_front();
  
  if (tipo == LAM) return;
  pos = arbol.insert(pos, valor);
  if (tipo == INT) {
    construccion(lista, arbol, pos.left());
    construccion(lista, arbol, pos.right());
  }
}

void list2btree(list<int> &L, btree<int> &B) {
  construccion(L, B, B.begin());
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=123;
  ev.eval<1>(list2btree,vrbs);
  return 0;
}
