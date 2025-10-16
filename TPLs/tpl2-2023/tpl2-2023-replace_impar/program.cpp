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
int DNI=98765432;  void reemplazar_rec(tree<int>::iterator n, tree<int> &T, std::map<int, int> &M, int max_v) {
  int& val = *n;
  if (val % 2 != 0) {
    auto it = M.find(val);
    if (it != M.end()) {
      val = it->second;
    } else {
      val = max_v;
    }
  }
  
  auto h = n.lchild();
  while (h != T.end()) {
    reemplazar_rec(h, T, M, max_v);
    ++h;
  }
}

void replace_impar(tree<int> &T, std::map<int, int> &M) {
  if (T.empty() || M.empty()) {
    return;
  }
  
  int max_v = std::numeric_limits<int>::min();
  for (const auto& p : M) {
    if (p.second > max_v) {
      max_v = p.second;
    }
  }
  
  reemplazar_rec(T.begin(), T, M, max_v);
}  


//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(replace_impar,vrbs);
  return 0;
}
