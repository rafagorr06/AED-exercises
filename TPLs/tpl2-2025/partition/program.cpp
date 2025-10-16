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

//codigo que ya tenía de recorrida de arbol, adaptado al problema
void recorrerarbol(tree<int> &T, tree<int>::iterator nodo, map<int,int>& ord_pre, map<int,int>& ord_post, int& a, int& b) {
  if (nodo == T.end()) {
    return;
  }
  ord_pre[*nodo] = a++;
  auto hijo = nodo.lchild();
  while (hijo != T.end()) {
    recorrerarbol(T, hijo, ord_pre, ord_post, a, b);
    hijo++;
  }
  ord_post[*nodo] = b++;
}

void partition(tree<int> &T, int n, map<int,string> &M) {
  if (T.empty()) {
    return;
  }
  map<int, int> ord_previo, ord_post;
  int cont_prev = 0, cont_post = 0;
  recorrerarbol(T, T.begin(), ord_previo, ord_post, cont_prev, cont_post);
  int n_prev = ord_previo[n];
  int n_post = ord_post[n];
  for (auto& it : ord_previo) {
    int m = it.first;
    if (m == n) M[m] = "NOD";
    else if (it.second < n_prev && ord_post[m] > n_post) M[m] = "ANT";
    else if (it.second > n_prev && ord_post[m] < n_post) M[m] = "DES";
    else if (it.second < n_prev && ord_post[m] < n_post) M[m] = "IZQ";
    else M[m] = "DER";
  }
}


//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(partition,vrbs);
  return 0;
}
