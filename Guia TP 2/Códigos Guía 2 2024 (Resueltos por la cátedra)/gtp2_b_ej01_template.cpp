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

	
///Asignar i a la posición del segundo elemento de la pila, con eliminación
/// Ejemplo: S = {1,2,3,4,5} -> S = {i,3,4,5}
void a_prima(stack<int> &S, int i){		
}

///Asignar i a la posición del segundo elemento de la pila, sin eliminación
/// Ejemplo: S = {1,2,3,4,5} -> S = {1,i,3,4,5}
void b_prima(stack<int> &S, int i){
}

///Asignar i a la posición del n-esimo elemento de la pila, eliminando
/// Ejemplo: n=4, S = {1,2,3,4,5} -> S = {i,5}		
void c_prima(stack<int> &S, int i, int n){		
}

///Asignar i a la posición del n-esimo elemento de la pila, sin eliminación
/// Ejemplo: n=4, S = {1,2,3,4,5} -> S = {i}	
void d_prima(stack<int> &S, int i){	
}
	
///Asignar i al fondo de la pila, sin eliminar
/// Ejemplo: S = {1,2,3,4,5} -> S = {1,2,3,4,i}	
	
void e_prima(stack<int> &S, int i){		
}
	
int main() {
	stack<int> S({5,4,3,2,1});
			
	cout<<endl<<"Pila: "<<endl;
	show_stack(S);		
	a_prima(S,6);
	b_prima(Sa,6);
	c_prima(Sa,6,4);
	d_prima(Sa,6);
	e_prima(S,6);
	cout<<endl<<"Pila: "<<endl;
	show_stack(Sa);		
	
	return 0;
}
