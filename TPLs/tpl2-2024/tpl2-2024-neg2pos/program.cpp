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

void neg2pos(list<int>& L, map<int,list<int>>& M){
  M.clear();
  auto p = L.begin();
  while (p!=L.end() && *p>=0) p++;
  while (p != L.end()){
    int key = *p++;
    M[key];
    while (p != L.end() && *p>=0){
      M[key].push_back(*p++);
    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(neg2pos,vrbs);
  return 0;
}
