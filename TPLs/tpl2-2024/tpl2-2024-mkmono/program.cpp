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

void mkmono(tree<int>::iterator n, int &last) {
  if (*n <= last) {
    *n = last + 1;
  }
  last = *n;
  
  tree<int>::iterator child = n.first_child();
  while (child != tree<int>::iterator()) {
    mkmono(child, last);
    child = child.next_sibling();
  }
}

void mkmono(tree<int> &T) {
  if (!T.empty()) {
    int last = *T.root() - 1;
    mkmono(T.root(), last);
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(mkmono,vrbs);
  return 0;
}
