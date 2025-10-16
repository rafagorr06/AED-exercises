#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Rafael Gorrochategui
int DNI=98765432;

int countheight(tree<int>::iterator n, tree<int>& t, map<int, int>& m) {
  int altura_max = -1;
  tree<int>::iterator it_altura = n.lchild();
  while (it_altura != t.end()) {
    int alt_hijo = countheight(it_altura, t, m);
    it_altura++;
    if (alt_hijo > altura_max) altura_max = alt_hijo;
  }
  int mi_altura = altura_max + 1;
  m[mi_altura]++;
  return mi_altura;
}

void countheight(tree<int> &T,map<int,int> &count) {
  if (T.empty()) return;
  countheight(T.begin(), T, count);
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(countheight,vrbs);
  return 0;
}
