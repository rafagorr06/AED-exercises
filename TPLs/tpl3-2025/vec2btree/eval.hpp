// GITVERSION: aed-2025-166-g06a6dc4d
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

  typedef bool (*vec2btree_t)(vector<int> &v,btree<int> &B);
  class eval1_t : public eval_base_t {
  public:
    vec2btree_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./v2b.json";
    }
    void run_case(json &data, json &outuser) {
      vector<int> v = data["v"];
      btree<int> B;
      outuser["retval"] = F(v,B);
      outuser["B"] = lisp_print(B);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      int n = 6+rnd.rand()%6;
      vector<int> v;
      for (int k=0; k<n; k++) 
        v.push_back(rnd.rand()%20);
      if (rnd.rand()%2==0) sort(v.begin(),v.end());
      datain["v"] = v;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,vec2btree_t>;
}
#undef CSTR

#endif
