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

void compact_queues(list<queue<int>> &LQ, int n) {
  for (auto &Q : LQ) {
    if ((int)Q.size() <= n) continue;
    queue<int> newQ;
    int count = 0, sum = 0;
    while (!Q.empty() && count < n) {
      newQ.push(Q.front());
      Q.pop();
      count++;
    }
    while (!Q.empty()) {
      sum += Q.front();
      Q.pop();
    }
    if (sum != 0) newQ.push(sum);
    Q = move(newQ);
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(compact_queues,vrbs);
  return 0;
}
