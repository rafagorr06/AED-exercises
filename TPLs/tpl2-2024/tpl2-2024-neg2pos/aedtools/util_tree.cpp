// GITVERSION: aed-2021-480-g1f515127
/* 
   COMIENZO DE DESCRIPCION 
   Utilitarios varios. 
   keywords: arbol orientado
   FIN DE DESCRIPCION 
*/
// -----------------------------------------------------------------
#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "tree.hpp"
#include "util.hpp"
#include "util_tree.hpp"
#include "json.hpp"

using namespace std;
using nlohmann::json;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  json tree2json(tree<int> &T,tree<int>::iterator n) {
    auto c=n.lchild();
    if (c==T.end()) return json(*n);
    json jn;
    jn.push_back(*n);
    while (c!=T.end()) 
      jn.push_back(tree2json(T,c++));
    return jn;
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  json tree2json(tree<int> &T) {
    json J;
    auto n=T.begin();
    if (n==T.end()) return J;
    return tree2json(T,n);
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  tree<int>::iterator
  json2tree(json &jn,tree<int> &T,tree<int>::iterator &n) {
    if (!jn.is_array()) {
      int xn = jn;
      n=T.insert(n,xn);
    } else {
      int xn = jn[0];
      n = T.insert(n,xn);
      auto c = n.lchild();
      int nc = jn.size()-1;
      for (int j=1; j<=nc; j++) {
        json2tree(jn[j],T,c);
        c++;
      }
    }
    return n;
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void json2tree(json &jT,tree<int> &T) {
    auto n=T.begin();
    json2tree(jT,T,n);
  }

  
  // -----------------------------------------------------------------
  void make_random_tree(tree<int> &T,tree<int>::iterator n,
			int M,int level,int siblings) {
    double lambda = 1.0/(double(siblings)/double(level)+1.0);
    n=T.insert(n,irand(M));
    tree<int>::iterator c=n.lchild();
    while (true) {
      if (drand()<lambda) break;
      make_random_tree(T,c,M,level+1,siblings);
      c=n.lchild();
    }
  }

  // -----------------------------------------------------------------
  void make_random_tree(tree<int> &T,int M,int siblings) {
    make_random_tree(T,T.begin(),M,1,siblings);
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // Makes a random tree with `s' siblings and `m' nodes.
  // The value at the node is in [0,M)
  void make_random_tree2(tree<int> &T,tree<int>::iterator n,
                         int M, int m,int s) {
    if (!m) return;
    // Toma los m nodos y los divide en `ss' siblings donde s es aleatorio
    // en [1,s]
    int ss = rand()%s+1;
    // Inserta un nodo en la raiz
    n = T.insert(n,rand()%M);
    m--; // toma en cuenta que ya inserto 1
    // Reparte los nodos que quedan aleatoriamente en los ss hijos
    vector<int> v(ss,0);
    for (int j=0; j<m; j++) v[rand()%ss]++;
    // A esta altura tenemos un vector v[] con s enteros
    // cuya suma es `m'.  Algunos pueden ser nulos, pero no importa
    // porque en ese caso la llamada recursiva no va a hacer nada. 
    for (unsigned int j=0; j<v.size(); j++) 
      make_random_tree2(T,n.lchild(),M,v[j],s);
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // Wrapper
  void make_random_tree2(tree<int> &T,int M, int m,int s) {
    T.clear();
    make_random_tree2(T,T.begin(),M,m,s);
  }

  // -----------------------------------------------------------------
  void  print_tree(tree<int> &t,node_t n,string pre,string c) {
    string pres;
    node_t p;
    int es_hoja;
    p=n.lchild();
    es_hoja=(p==t.end());
    cout << pre << "+--" << "(" << * n << ")" << endl;
    if (!es_hoja) cout << pre << c <<  "  |" << endl;
    while (p!=t.end()) {
      pres=pre+c+ "  ";
      if (p.right()!=t.end()) {
        print_tree(t,p++,pres,"|");}
      else { 
        print_tree(t,p++,pres," ");
      }
    }
    if (!es_hoja) cout << pre <<  c << endl;
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void  print_tree(tree<int> &t) {
    string pre("");
    if (t.begin()!=t.end()) print_tree(t,t.begin(),pre," ");
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void list2treev(tree<int> &T,int TERM,int BP,
                  int EP,va_list elems) {
    list<int> L;
    add_to_list(L,TERM,elems);
    list2tree(T,L,BP,EP);
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // Load tree from list of node values
  void list2treev(tree<int> &T,int TERM,int BP,int EP,...) {
    va_list elems;
    va_start(elems,EP);
    list2treev(T,TERM,BP,EP,elems);
    va_end(elems);
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void vec2map(vector<int> &v,map<int,int> &M) {
    assert(v.size()%2==0);
    int n=v.size()/2;
    M.clear();
    for (int j=0; j<n; j++) M[v[2*j]] = v[2*j+1];
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void json2map(json &JM,map<int,int> &M) {
    for (auto &p : JM) {
      M[p[0]] = p[1];
    }
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void map2json(json &JM,map<int,int> &M) {
    for (auto &p : M) {
      json z = {p.first,p.second};
      JM.push_back(z);
    }
  }
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  int tree2dot(tree<int> &T,tree<int>::iterator n,int id,
               ostream &out,map<int,string> &id2key) {
    if (n==T.end()) return id;
    auto p = id2key.find(*n);
    string key=(p==id2key.end()? to_string(*n) : p->second);
    out << id << " [label=\"" << key << "\"];\n";
    auto c = n.lchild();
    int idc=id+1;
    while (c!=T.end()) {
      out << id << " -> " << idc << ";\n";
      idc=tree2dot(T,c++,idc,out,id2key);
    }
    return idc;
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void tree2dot(tree<int> &T,const char *file
                ,map<int,string> &id2key) {
    ofstream out(file? file : "tree.dot");
    out << "digraph G {\n";
    tree2dot(T,T.begin(),0,out,id2key);
    out << "}\n";
    out.close();
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  void parsetreeline(string &line,string &newline,
                       map<int,string> &id2key) {
    // newline: Contains the transformed line
    int j=0,n=line.size(),id=0;
    while (j<n) {
      string key;
      while (1) {
        char c=line[j];
        // All the chars that are acceptable in a key
        if (!((c>='a' && c<='z') 
              || c=='.' || c=='-'
              || (c>='A' && c<='Z')
              || (c>='0' && c<='9'))) break;
        key.push_back(c); j++;
      }
      if (key.size()>0) {
        newline += to_string(id);
        id2key[id++]=key;
      } else newline.push_back(line[j++]);
    }
    // for (auto &p:id2key) 
    //   cout << p.first << "-> " << p.second << endl;
  }
  
}
// -------------------------------------------------------------------
