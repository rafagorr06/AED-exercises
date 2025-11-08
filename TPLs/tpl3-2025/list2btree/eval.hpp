// GITVERSION: aed-2025-166-g06a6dc4d
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include <forward_list>
#include <sstream>
#include <climits>
using namespace std;

extern const int INT,HOJ,LAM;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  void b2l(json &L,btree<int> &B,btree<int>::iterator n) {
    if (n==B.end()) {
      L.push_back("LAM");
      L.push_back(0);
      return;
    }
      
    auto cl=n.left(),cr=n.right();
    if (cl==B.end() && cr==B.end()) {
      L.push_back("HOJ");
      L.push_back(*n);
    } else {
      L.push_back("INT");
      L.push_back(*n);
      b2l(L,B,cl);
      b2l(L,B,cr);
    }
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*list2btree_t)(list<int> &L,btree<int> &B);
  class eval1_t : public eval_base_t {
  public:
    list2btree_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./l2b.json";
    }
    void run_case(json &data, json &outuser) {
      json &jL = data["L"];
      auto p = jL.begin();
      list<int> L;
      while (p!=jL.end()) {
        if (*p=="INT") L.push_back(INT);
        else if (*p=="HOJ") L.push_back(HOJ);
        else if (*p=="LAM") L.push_back(LAM);
        else {
          cout << "jL " << jL << endl;
          cout << "p " << *p << endl;
          throw std::runtime_error("bad p value");
        }
        p++;
        L.push_back(*p++);
      }
      btree<int> B;
      F(L,B);
      outuser["B"] = btree2lisp(B);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      btree<int> B;
      make_random_btree(B,10,0.5,rnd);
      cout << lisp_print(B) << endl;
      json L;
      b2l(L,B,B.begin());
      cout << json(L) << endl;
      datain["L"] = L;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,list2btree_t>;
}
#undef CSTR

#endif
