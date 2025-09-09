// GITVERSION: aed-2021-572-gdb01cdf5
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include <forward_list>
#include <sstream>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  json q2j(queue<int> q) {
    json rv;
    while (!q.empty()) {
      rv.push_back(q.front());
      q.pop();
    }
    return rv;
  }
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*gfibo_seed_t)(list<int> &L,int MM,list<int> &Lseed);
  class eval1_t : public eval_base_t {
  public:
    gfibo_seed_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./gfibo.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      list<int> L = data["L"];
      int M = data["M"];
      list<int> Lseed;
      F(L,M,Lseed);
      outuser["Lseed"] = Lseed;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      int MM = 2+rnd.rand()%3;
      int M = 1+rnd.rand()%3;
      json Lseed;
      for (int k=0; k<MM; k++)
        Lseed.push_back(rnd.rand()%5);
      json L=Lseed;
      int N=2+rnd.rand()%10;
      int p=0;
      for (int k=0; k<N; k++) {
        int sum=0;
        for (int l=0; l<MM; l++) sum += int(L[k+l]);
        L.push_back(sum);
      }
      datain["L"] = L;
      datain["M"] = M;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,gfibo_seed_t>;
}
#undef CSTR

#endif
