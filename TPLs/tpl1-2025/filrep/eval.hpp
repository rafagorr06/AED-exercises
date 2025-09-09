// GITVERSION: aed-2021-605-gfd46d76d
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

  typedef bool (*filter_rep_t)(queue<int>& inputs);
  class eval1_t : public eval_base_t {
  public:
    filter_rep_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./filr.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      queue<int> inputs;
      for (auto x: data["inputs"]) inputs.push(x);
      outuser["retval"] = F(inputs);
      json &out = outuser["inputs"];
      out = json::array();
      while (!inputs.empty()) {
        out.push_back(inputs.front());
        inputs.pop();
      }
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      json &inputs = datain["inputs"];
      int N = 5+rnd.rand()%10;
      for (int k=0; k<N; k++) 
        inputs.push_back(rnd.rand()%10);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,filter_rep_t>;
}
#undef CSTR

#endif
