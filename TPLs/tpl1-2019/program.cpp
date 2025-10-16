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

list<vector<int>> Pareto(list<vector<int>>&L){
  // COMPLETAR AQUI...
  return list<vector<int>>();
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void merge_kway(vector<queue<int>> &qords, queue<int> &merged) {
  for(auto &cola : qords){
    if(cola.empty()){
      qords.erase(cola);
    }
    
  }
}

bool is_balanced(string &c) {
  // COMPLETAR AQUI...
  return true;
}
 
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  cout << "seed: 123" << endl;
  do {
//    ev.eval<1>(Pareto,vrbs);
//    h1 = ev.evalr<1>(Pareto,seed,vrbs);

    ev.eval<2>(merge_kway,vrbs);
    h2 = ev.evalr<2>(merge_kway,seed,vrbs);
    
//    ev.eval<3>(is_balanced,vrbs);
//    h3 = ev.evalr<3>(is_balanced,seed,vrbs);
//    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
