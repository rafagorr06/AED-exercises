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

vector<pair<int,int>> cartesian_product(const set<int> &A,const set<int> &B) {
  vector<pair<int,int>> product;
  for (int a:A){
    for (int b:B){
      product.push_back({a,b});
    }
  }
  return product;
}

int sum_diff_abs_pairs(const vector<pair<int,int>> &pairs) {
  int sum = 0;
  for (const auto &p:pairs) {
    sum += abs(p.first-p.second);
  }
  return sum;
}

// Funcion principal que calcula la sumatoria del producto cartesiano
int sumcartesian(set<int> &A, set<int> &B) {
  auto product = cartesian_product(A,B);
  return sum_diff_abs_pairs(product);
}


//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(sumcartesian,vrbs);
  return 0;
}
