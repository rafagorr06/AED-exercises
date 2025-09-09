#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

void show_list(list<string>& L) {
	cout<<"(";
	for(list<string>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")";
}

list<char> string_to_list(char * S) {
	list<char> letras;
	int i = 0;
	while (S[i] != '\0') {
		if (S[i] != ' '){
			letras.push_back(S[i]);
		}
		i++;
	}
	return letras;
}

bool is_palindromo (char * S) {
	
}

int main(int argc, char *argv[]) {
	char predicado[] = "alli si maria avisa y asi va a ir a mi silla";	
	
	cout << "Predicado: " << predicado << endl;
	
	bool z = is_palindromo(predicado);
	if (z) 
	{
	cout << "Es palíndromo" <<	endl;	
	}
	else
	{
	cout << "No es palíndromo" <<	endl;
	}
	
	return 0;
}





