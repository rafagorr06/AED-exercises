// GITVERSION: aed-2025-138-g1460dcd6
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include <forward_list>
#include <sstream>
#include <climits>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*partition_t)(tree<int> &T,int n,map<int,string> &M);
  class eval1_t : public eval_base_t {
  public:
    partition_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./part.json";
    }
    void run_case(json &data, json &outuser) {
      tree<int> T;
      // cout << "data: " << data << endl;
      string sT=data["T"];
      lisp2tree(sT,T);
      int n=data["n"];
      map<int,string> M;
      F(T,n,M);
      json rv;
      for (auto &p : M) {
        rv.push_back(p.first);
        rv.push_back(p.second);
      }
      outuser["M"].swap(rv);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      make_random_tree2(T,1,10,3,rnd);
      fill_ids(T);
      int sz= T.size();
      datain["T"] = tree2lisp(T);
      datain["n"] = rnd.rand()%sz;
      // cout << "datain: " << datain << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,partition_t>;
}
#undef CSTR

#endif
