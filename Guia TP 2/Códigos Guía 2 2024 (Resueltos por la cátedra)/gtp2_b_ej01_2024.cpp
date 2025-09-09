#include <iostream>
#include <stack>

using namespace std;

void show_stack(stack<int> S){
	cout<<"(";
	while (!S.empty())
	{
		cout << S.top()<< " ";
		S.pop();
	}
	cout<<")"<<endl;
}

/// S.top() -> devuelve el elemento superior sin eliminarlo
/// S.pop() -> elimina el el elemento superior
/// S.push(i)	-> agrega i en el tope de la pila
/// S.empty() -> booleano, true si esta vacia
	
	
///Asignar i a la posición del segundo elemento de la pila, con eliminación
/// Ejemplo: S = {1,2,3,4,5} -> S = {i,3,4,5}
void a_prima(stack<int> &S, int i){		
	for(int j=0;j<2;j++) {
		if(!S.empty()){
			S.pop();
		}
	}
	S.push(i);
}

///Asignar i a la posición del segundo elemento de la pila, sin eliminación
/// Ejemplo: S = {1,2,3,4,5} -> S = {1,i,3,4,5}
void b_prima(stack<int> &S, int i)
{
	int aux = S.top();
	S.pop();
	S.pop();
	S.push(i);
	S.push(aux);		
}

///Asignar i a la posición del n-esimo elemento de la pila, eliminando
/// Ejemplo: n=4, S = {1,2,3,4,5} -> S = {i,5}		
void c_prima(stack<int> &S, int i, int n){
	for(int j=0;j<n;j++) {
		if(!S.empty()){
			S.pop();
		}
	}
	S.push(i);
}

///Asignar i a la posición del n-esimo elemento de la pila, sin eliminación

///Asigna i al fondo, vaciando la pila
/// Ejemplo: n=4, S = {1,2,3,4,5} -> S = {i}	
	
void d_prima(stack<int> &S, int i)
{	
	while(!S.empty()) {
		S.pop();
	}
	S.push(i);
}
	
///Asignar i al fondo de la pila, sin eliminar
/// Ejemplo: S = {1,2,3,4,5} -> S = {1,2,3,4,i}	--- modo a

/// Ejemplo: S = {1,2,3,4,5} -> S = {1,2,3,4,5,i}	--- modo b
	
void e_prima(stack<int> &S, int i){		
	stack<int> Saux;
	
	while(!S.empty()) {
		Saux.push(S.top());
		S.pop();
	}
	//quedo vacia S, Saux tiene los de S, pero invertidos
	
	S.push(i);
	/// Saux.pop(); ---modo a
	
	while(!Saux.empty()) {
		S.push(Saux.top());
		Saux.pop();
	}
}
	
int main() {
	stack<int> S({5,4,3,2,1});
			
	cout<<endl<<"Pila: "<<endl;
	show_stack(S);		
	a_prima(S,6);
//	b_prima(S,6);
//	c_prima(S,6,4);
//	d_prima(S,6);
//	e_prima(S,6);
	cout<<endl<<"Pila: "<<endl;
	show_stack(S);		
	
	return 0;
}
