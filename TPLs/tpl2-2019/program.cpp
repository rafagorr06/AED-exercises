#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

void fill_ordprev_aux(tree<int>& T, tree<int>::iterator it, list<int>& L) {
  if (it == T.end() || L.empty()) {
    return;
  }
  // 1. Procesa el nodo actual (raíz del subárbol) - Orden Previo
  *it = L.front();
  L.pop_front();
  
  // 2. Llama recursivamente para cada hijo
  tree<int>::iterator child_it = it.lchild();
  while (child_it != T.end() && !L.empty()) {
    fill_ordprev_aux(T, child_it, L);
    child_it++; // Avanza al siguiente hermano
  }
}

void fill_ordprev(tree<int> &T,list<int> &L) {
  if (!T.empty()) {
    fill_ordprev_aux(T, T.begin(), L);
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void a_lo_ancho(graph& G, tree<char>& T){
  T.clear();
  if (G.empty()) return;
  
  queue<char> q;
  set<char> visited;
  // Mapa para asociar el valor de un nodo con su iterador en el árbol
  map<char, tree<char>::iterator> node_map;
  
  // 1. Iniciar con el primer vértice del grafo como raíz [cite: 31]
  char root_val = G.begin()->first;
  q.push(root_val);
  visited.insert(root_val);
  
  // Insertar la raíz en el árbol y guardar su iterador
  T.insert(T.begin(), root_val);
  node_map[root_val] = T.begin();
  
  // 2. Búsqueda a lo ancho (BFS)
  while (!q.empty()) {
    char current_v = q.front();
    q.pop();
    
    tree<char>::iterator parent_it = node_map[current_v];
    
    // 3. Añadir los vecinos no visitados como hijos
    for (char neighbor : G[current_v]) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
        
        // --- Lógica para añadir un hijo al final ---
        // La librería no tiene `append_child`, usamos `insert`.
        // Debemos encontrar el punto de inserción (el final de la lista de hijos).
        tree<char>::iterator insert_point = parent_it.lchild();
        while(insert_point != T.end()) {
          insert_point++; // Iterar sobre los hermanos hasta el final
        }
        
        // Insertar el nuevo nodo en la posición encontrada
        tree<char>::iterator child_it = T.insert(insert_point, neighbor);
        node_map[neighbor] = child_it;
      }
    }
  }
}

  void intersect_map(map<int,list<int>> &A, map<int,list<int>> &B,map<int,list<int>> &C){
    C.clear();
    
    // 1. Iterar sobre el mapa A usando un iterador compatible con C++11
    for (auto const& pairA : A) {
      int key = pairA.first;
      const list<int>& listA = pairA.second;
      
      // 2. Buscar si la clave existe en B
      auto itB = B.find(key);
      if (itB != B.end()) {
        const list<int>& listB = itB->second;
        list<int> intersection_list;
        
        // 3. Algoritmo manual para la intersección de listas ordenadas
        auto iterA = listA.begin();
        auto iterB = listB.begin();
        while (iterA != listA.end() && iterB != listB.end()) {
          if (*iterA < *iterB) {
            ++iterA;
          } else if (*iterB < *iterA) {
            ++iterB;
          } else { // Son iguales
            intersection_list.push_back(*iterA);
            ++iterA;
            ++iterB;
          }
        }
        
        // 4. Si la intersección no es vacía, añadirla al mapa C
        if (!intersection_list.empty()) {
          C[key] = intersection_list;
        }
      }
    }
  }

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  cout << "seed: 123" << endl;
  do {
//    ev.eval<1>(fill_ordprev,vrbs);
//    h1 = ev.evalr<1>(fill_ordprev,seed,vrbs);
//
//    ev.eval<2>(a_lo_ancho,vrbs);
//    h2 = ev.evalr<2>(a_lo_ancho,seed,vrbs);
    
    ev.eval<3>(intersect_map,vrbs);
    h3 = ev.evalr<3>(intersect_map,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
