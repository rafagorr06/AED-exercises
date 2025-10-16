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

int contar_impares(tree<int>::iterator n, tree<int> &T) {
  int c = 0;
  auto h = n.lchild();
  while (h != T.end()) {
    if (*h % 2 != 0) c++;
    ++h;
  }
  return c;
}

void recorrer(tree<int>::iterator n, tree<int> &T, std::map<int, int> &M) {
  if (n == T.end()) return;
  
  if (*n % 2 != 0) {
    M[*n] = contar_impares(n, T);
  }
  
  auto h = n.lchild();
  while (h != T.end()) {
    recorrer(h, T, M);
    ++h;
  }
}

void tree2isib(tree<int> &T, std::map<int, int> &M) {
  if (!T.empty()) {
    recorrer(T.begin(), T, M);
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(tree2isib,vrbs);
  return 0;
}
