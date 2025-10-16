#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

void classify_relative(tree<int> &T,
                       int n1,int n2,int &m1, int&m2) {
  // COMPLETAR AQUI....
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
float prom_path(tree<int> &T) {
  // COMPLETAR AQUI....
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void filtra_deps(map<string,list<string>> &G,
                 list<string> &L) {
  // COMPLETAR AQUI....
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {

    ev.eval<1>(classify_relative,vrbs);
    h1 = ev.evalr<1>(classify_relative,seed,vrbs);

    ev.eval<2>(prom_path,vrbs);
    h2 = ev.evalr<2>(prom_path,seed,vrbs);

    ev.eval<3>(filtra_deps,vrbs);
    h3 = ev.evalr<3>(filtra_deps,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
