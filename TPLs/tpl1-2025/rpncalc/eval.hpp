// GITVERSION: aed-2021-582-gf1162ad6
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

  typedef int (*rpncalc_t)(queue<int> &vals);
  class eval1_t : public eval_base_t {
  public:
    rpncalc_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./rcal.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      queue<int> vals;
      json Lj = data["vals"];
#define CHECK(OP) else if (x.is_string() && x==#OP) vals.push(OP)
      for (auto &x : Lj)
        if (0) {}
      // CHECK SUMA
      CHECK(SUMA);
      CHECK(RESTA);
      CHECK(PROD);
      CHECK(DIV);
      else vals.push(x);
      int retval = F(vals);
      if (retval==ERROR) outuser["retval"] = "ERROR";
      else outuser["retval"] = retval;
      // cout << data["vals"] << "      " << outuser["retval"] << endl;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

#define EXPAND (INT_MAX-10)
    void generate_case(randomg_t &rnd,json &datain) {
      list<int> vals;
      vals.push_back(EXPAND);
      while (1) {
        auto p = find(vals.begin(),vals.end(),EXPAND);
        if (p==vals.end()) break;
        int r = rnd.rand()%4;
        // *p = (r==0? SUMA: r==1? RESTA : r==2? PROD : DIV);
        *p = (r==0? SUMA: r==1? RESTA : r==2? PROD : SUMA);
        for (int k=0; k<2; k++) {
          int x = rnd.rand()%8;
          p = vals.insert(p,(x<5? x : EXPAND));
          // p = vals.insert(p,rnd.rand()%5);
        }
      }
      json &jvals = datain["vals"];
      jvals = json::array();
#define CHECK2(OP) else if (x==OP) jvals.push_back(#OP)
      for (auto x : vals) {
        if (0) {}
        CHECK2(SUMA);
        CHECK2(RESTA);
        CHECK2(PROD);
        CHECK2(DIV);
        else jvals.push_back(x);
      }
      int mut = rnd.rand()%13;
      if (mut==0) jvals.insert(jvals.begin(),5);
      else if (mut==1) jvals.erase(jvals.begin());
      else if (mut==2) jvals.push_back(SUMA);
      // cout << jvals << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,rpncalc_t>;
}
#undef CSTR

#endif
