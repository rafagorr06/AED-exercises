#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

//Nombre: Rafael Gorrochategui
int DNI=47104952;

void finddup(list<int> &L, list<int> &Ldup) {
  for (auto p = L.begin(); p != L.end(); ++p) {
    auto q = p; ++q;
    for (; q != L.end(); ++q) {
      auto it1 = p, it2 = q;
      list<int> Laux;
      while (it1 != L.end() && it2 != L.end() && *it1 == *it2) {
        Laux.push_back(*it1);
        ++it1; ++it2;
      }
      if (Laux.size() > Ldup.size()) {
        Ldup = Laux;
      }
    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(finddup,vrbs);
  return 0;
}
