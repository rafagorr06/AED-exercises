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

void coverset(list<set<int>> &LA, list<set<int>> &LB, set<int> &UA, set<int> &B) {
  for (auto conj_b : LB) {
    set<int> u_a;
    for (auto conj_a : LA) {
      set<int> u_a_siguiente;
      set_union(u_a.begin(), u_a.end(), conj_a.begin(), conj_a.end(),
      inserter(u_a_siguiente, u_a_siguiente.begin()));
      u_a = u_a_siguiente;
      set<int> dif;
      set_difference(conj_b.begin(), conj_b.end(), u_a.begin(), u_a.end(),
      inserter(dif, dif.begin()) );
      if (dif.empty()) {
        UA = u_a;
        B = conj_b;
        return;
      }
    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(coverset,vrbs);
  return 0;
}
