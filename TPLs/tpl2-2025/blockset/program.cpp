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

bool blockset(map<int,list<int>> &G, list<int> &barrera, int A, int B) {
  list<int> cola;
  list<int> visitados;
  if (find(barrera.begin(), barrera.end(), A) != barrera.end()) return true;
  cola.push_back(A);
  visitados.push_back(A);
  while (!cola.empty()) {
    int v = cola.front();
    cola.pop_front();
    auto it = G.find(v);
    if (it != G.end()) {
      for (int vecino : it->second) {
        if (find(visitados.begin(), visitados.end(), vecino) == visitados.end() 
          && find(barrera.begin(), barrera.end(), vecino) == barrera.end()) {
          visitados.push_back(vecino);
          cola.push_back(vecino);
        }
      }
    }
    if (v == B) return false;
  }
  return true;
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(blockset,vrbs);
  return 0;
}
