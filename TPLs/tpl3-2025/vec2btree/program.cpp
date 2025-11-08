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

void loadbtree(vector<int> &v, int pos, btree<int> &B, btree<int>::iterator n) {
  if (pos < v.size()) {
    n = B.insert(n, v[pos]);
    loadbtree(v,2*pos+1, B, n.left());
    loadbtree(v,2*pos+2, B, n.right());
  }
}

bool isheap(btree<int> &B, btree<int>::iterator n) {
  if (n == B.end()) return true;
  auto it_izq = n.left();
  auto it_der = n.right();
  bool izqOk = (it_izq == B.end()) or (*n <= *it_izq);
  bool derOk = (it_der == B.end()) or (*n <= *it_der);
  return izqOk && derOk && isheap(B, it_izq) && isheap(B, it_der);
}

bool vec2btree(vector<int> &v,btree<int> &B) {
  loadbtree(v, 0, B, B.begin());
  return isheap(B, B.begin());
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(vec2btree,vrbs);
  return 0;
}
