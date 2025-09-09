#define USECHRONO
#undef HAVE_MPI

const int SUMA=10000000, 
  RESTA=(SUMA+1),
  PROD= (SUMA+2),
  DIV = (SUMA+3),
  ERROR= (SUMA+4);

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

int rpncalc(queue<int> &vals) {
  stack<int>pila_auxiliar;
  
  while (!vals.empty()){
    int oper = vals.front();
    vals.pop();
    
    if(oper == SUMA or oper == RESTA or oper == PROD or oper == DIV){
      
      int num1 = pila_auxiliar.top();
      pila_auxiliar.pop();
      int num2 = pila_auxiliar.top();
      pila_auxiliar.pop();
      
      if (oper == SUMA){
        pila_auxiliar.push(num2+num1);
      }
      if(oper == RESTA){
        pila_auxiliar.push(num2-num1);
      };
      if(oper == PROD){
        pila_auxiliar.push(num2*num1);
      }
      if(oper == DIV){
        pila_auxiliar.push(num2/num1);
      }
    } else {
      pila_auxiliar.push(oper);
    }
  }
  
  if(pila_auxiliar.size() != 1){
    return ERROR;
  } else {
    int resultado = pila_auxiliar.top();
    return resultado;
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(rpncalc,vrbs);
  return 0;
}
