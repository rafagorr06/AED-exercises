// GITVERSION: aed-2021-474-g3872e391
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

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*sortchild_t)(tree<int> &T,tree<int> &Q);
  class eval1_t : public eval_base_t {
  public:
    sortchild_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./sc.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      tree<int> T,Q;
      string s = data["T"];
      lisp2tree(s,T);
      F(T,Q);
      outuser["Q"] = tree2lisp(Q);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      tree<int> Quser,Qref;
      lisp2tree(string(outuser["Q"]),Quser);
      lisp2tree(string(outref["Q"]),Qref);
      return Quser==Qref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      int m = 5+rnd.rand()%10;
      int n = 5+rnd.rand()%10;
      make_random_tree2(T,5,m,n,rnd);
      datain["T"] = tree2lisp(T);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,sortchild_t>;
}
#undef CSTR

#endif
