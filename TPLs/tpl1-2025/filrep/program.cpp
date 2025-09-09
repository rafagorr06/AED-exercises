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

bool filter_rep(queue<int>& inputs) {
  
  if (inputs.empty()) {
    return false;
  }
  
  bool duplicado = false;
  int tamanio = inputs.size();
  int cuenta=0;
    
  while (cuenta < tamanio){
    int actual = inputs.front();
    inputs.pop();
    cuenta++;
    
    if (cuenta < tamanio){
    if (actual == inputs.front()) {
      duplicado = true;
    } else {
      inputs.push(actual);
    }
  } else {
      inputs.push(actual);
    }
  }
  return duplicado;
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(filter_rep,vrbs);
  return 0;
}
