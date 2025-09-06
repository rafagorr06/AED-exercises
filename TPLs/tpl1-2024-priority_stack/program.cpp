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

void priority_stack(list<list<int>> &LL, stack<int> &S) {
    list<int>lista_ordenada;
    for(auto &sublista : LL){
    lista_ordenada.splice(lista_ordenada.end(),sublista);
    }
    lista_ordenada.sort();
    lista_ordenada.reverse();
    
    for(auto it = lista_ordenada.begin() ; it!=lista_ordenada.end() ; ++it){
      S.push(*it);
    }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(priority_stack,vrbs);
  return 0;
}
