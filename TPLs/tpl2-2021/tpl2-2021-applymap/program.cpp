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
// Nombre: Bob Esponja
int DNI=98765432;

  void applymap_rec(tree<int>::iterator n, tree<int> &T, std::map<int, int> &M) {
    *n = M.at(*n);
    auto hijo = n.lchild();
    while (hijo != T.end()) {
      if (M.count(*hijo)) {
        applymap_rec(hijo, T, M);
        ++hijo;
      } else {
        hijo = T.erase(hijo);
      }
    }
  }
  
  void applymap(tree<int> &T, std::map<int, int> &M) {
    if (T.empty()) {
      return;
    }
    auto raiz = T.begin();
    if (M.count(*raiz)) {
      applymap_rec(raiz, T, M);
    } else {
      T.clear();
    }
  }

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(applymap,vrbs);
  return 0;
}
