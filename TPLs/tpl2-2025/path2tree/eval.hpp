// GITVERSION: aed-2025-129-g294d2c53
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

  typedef void (*path2tree_t)(list<list<int>> &paths,int root,tree<int> &T);
  class eval1_t : public eval_base_t {
  public:
    path2tree_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./p2t.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      list<list<int>> paths;
      json &jlists = data["paths"];
      for (auto &l : jlists) {
        list<int> L = l;
        paths.push_back(L);
      }
      int root = data["root"];
      tree<int> T;
      F(paths,root,T);
      outuser["T"] = lisp_print(T);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

#if 0
    void mkpaths(tree<int> &T,tree<int>::iterator n,
                 list<list<int>> &paths,list<int> &current) {
      if (n==T.end()) {
        cout << json(current) << endl;
        if (!current.empty()) paths.push_back(current);
        return;
      }
      cout << "n " << *n << endl;
      auto c=n.lchild();
      mkpaths(T,c,paths,current);        
      if (c==T.end()) return;
      c++;
      while (c!=T.end()) {
        current.clear();
        current.push_back(*n);
        current.push_back(*c);
        mkpaths(T,c++,paths,current);
      }
    }
#endif

    list<list<int>> mkpaths(tree<int> &T,tree<int>::iterator n) {
      list<list<int>> paths;
      if (n==T.end()) { return paths; }

      auto c=n.lchild();

      if (c==T.end()) {
        list<int> l= {*n};
        paths.push_back(l);
        return paths;
      }
      
      while (c!=T.end()) {
        list<list<int>> cpaths = mkpaths(T,c++);
        int j=0;
        for (auto &path : cpaths) {
          if (j++==0) path.insert(path.begin(),*n);
          paths.push_back(path);
        }
      }
      return paths;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      make_random_tree2(T,1,6,3,rnd);
      fill_ids(T);
      // cout << lisp_print(T) << endl;
      list<list<int>> paths;
      paths = mkpaths(T,T.begin());
      json &jpaths = datain["paths"];
      for (auto &path : paths) {
        //cout << json(path) << endl;
        jpaths.push_back(json(path));
      }
      datain["root"] = *T.begin();
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,path2tree_t>;
}
#undef CSTR

#endif
