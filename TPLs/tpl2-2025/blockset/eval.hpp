// GITVERSION: aed-2025-128-ge349f666
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

  json gdump(map<int,list<int>> &G) {
    json rv;
    for (auto &p : G) {
      json q;
      q.push_back(p.first);
      q.push_back(json(p.second));
      rv.push_back(q);
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

  typedef bool (*blockset_t)(map<int,list<int>> &G,list<int> &barrier,int A,int B);
  class eval1_t : public eval_base_t {
  public:
    blockset_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./bs.json";
    }
    void run_case(json &data, json &outuser) {
      json &jG = data["G"];
      map<int,list<int>> G;
      for (auto &q : jG) {
        int x = q[0];
        for (auto y : q[1]) 
          G[x].push_back(y);
      }
      
      json &jbar = data["barrier"];
      list<int> barrier;
      for (auto x : jbar)
        barrier.push_back(x);
      int A = data["A"];
      int B = data["B"];
      outuser["retval"] = F(G,barrier,A,B);
      
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    
    void generate_case(randomg_t &rnd,json &datain) {
      // Nbr of vrtx in each branch
      map<int,list<int>> G;
      int N=4,nbranch=3;
      for (int j=0; j<nbranch; j++) {
        for (int k=0; k<N; k++) {
          int y,x = 2+j*N+k;
          y=(k==0? 0 : x-1);
          G[x].push_back(y);
          y=(k==N-1? 1 : x+1);
          G[x].push_back(y);
        }
      }
      // Symmetryze
      map<int,list<int>> G2;
      for (auto &q : G) {
        int x = q.first;
        for (auto y : q.second) {
          if (x!=y) {
            G2[x].push_back(y);
            G2[y].push_back(x);
          }
        }
      }
      G2.swap(G);
      G2.clear();

      json jG;
      for (auto &q : G) {
        auto &L = q.second;
        L.sort();
        L.unique();
      }
      datain["G"] = gdump(G);
      // cout << gdump(G) << endl;
      // We take two random nodes
      // and make the barrier with other 3 or more random nodes
      int m=nbranch*N+2;
      vector<int> w;
      for (int k=0; k<m; k++) w.push_back(k);
      random_shuffle(rnd,w);
      datain["A"]=w[0];
      datain["B"]=w[1];
      int nb=4;
      for (int k=0; k<nb; k++)
        datain["barrier"].push_back(w[2+k]);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,blockset_t>;
}
#undef CSTR

#endif
