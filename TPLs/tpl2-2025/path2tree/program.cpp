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


void path2tree(list<list<int>> &paths, int root, tree<int> &T) {
  T.clear();
  //insertar la raiz para empezar el armado
  T.insert(T.begin(), root);
  for (list<int> &caminos : paths) {
    tree<int>::iterator it1 = T.find(caminos.front());
    auto it2 = caminos.begin();
    it2++;
    while (it2!=caminos.end()) {
      int valornodo = *it2;
      tree<int>::iterator it3 = it1.lchild();
      while (it3 != T.end() && *it3 != valornodo) {
        it3++;
      }
      if (it3 == T.end()) {
        it1 = T.insert(it3, valornodo);
      } else {
        it1 = it3;
      }
      it2++;
    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(path2tree,vrbs);
  return 0;
}
