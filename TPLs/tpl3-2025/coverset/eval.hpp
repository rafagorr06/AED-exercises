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

  typedef void (*coverset_t)(list<set<int>> &LA,list<set<int>> &LB,
                             set<int> &UA,set<int> &B);
  class eval1_t : public eval_base_t {
  public:
    coverset_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./cvs.json";
    }
    void run_case(json &data, json &outuser) {
      list<set<int>> LA,LB;
      for (auto &jA : data["LA"]) {
        set<int> A = jA;
        LA.push_back(A);
      }
      for (auto &jB : data["LB"]) {
        set<int> B = jB;
        LB.push_back(B);
      }
      set<int> UA,B;
      F(LA,LB,UA,B);
      outuser["UA"] = UA;
      outuser["B"] = B;
      // cout << "OK " << !UA.empty() << endl;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      int
        nsa=5+rnd.rand()%5,
        nsb=5+rnd.rand()%5;
      int max=10;
      json LA,LB;
      for (int k=0; k<nsa; k++) {
        int na = 3+rnd.rand()%5;
        set<int> A;
        for (int l=0; l<na; l++)
          A.insert(rnd.rand()%max);
        LA.push_back(A);
      }
      // cout << "LA: " << LA << endl;
      for (int k=0; k<nsb; k++) {
        int nb = 3+rnd.rand()%5;
        set<int> B;
        for (int l=0; l<nb; l++)
          B.insert(rnd.rand()%max);
        LB.push_back(B);
      }
      datain["LA"].swap(LA);
      datain["LB"].swap(LB);
      // cout << "LB: " << LB << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,coverset_t>;
}
#undef CSTR

#endif
