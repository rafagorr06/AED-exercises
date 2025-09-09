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
			letras.push_back(toupper(S[i]));			
		}
		i++;
	}
	return letras;
}

bool is_palindromoJA (char * S) {
	list<char> L = string_to_list(S);
	auto it = L.begin();
	auto it_reverse = prev(L.end());
	
	while(it!=it_reverse and it_reverse!=prev(it))
	{
		if(*it==*it_reverse){
			it++;
			it_reverse--;
		}
		else {
			return false;
		}
	}
	return true;
}

bool is_palindromoVA (char * S) {
	list<char> l = string_to_list(S);
	list<char>::iterator it_b = l.begin();
	list<char>::iterator it_e = prev(l.end());
	
	int iterations = (l.size() % 2 == 0) ? l.size()/2 : int(l.size()/2);
	
	for (int i = 0; i<iterations; ++i){
		if (*it_b != *it_e){
			cout<<*it_b<<endl;
			cout<<*it_e<<endl;
			return false;
		}
		
		it_b++;
		it_e--;
	}
	return true;
}

bool is_palindromoKV(char* S){
	list<char>L;
	L=string_to_list(S);
	
	auto it1 =L.begin();
	auto it2 = L.rbegin();
	
	for(int i=0;i<L.size();i++)
	{
		if(*it1==*it2)
		{
			it1++;
			it2++;
		}else{return false;}
	}
	return true;
}

/*
bool is_palindromoMG(char* S){
	list<char>L;
	for(int i=0;i<strlen(S);i++){
		if(S[i]!=' '){
			L.push_back(S[i]);
		}
	}
	list<char>L_alrevez=L;
	L_alrevez.reverse();
	if(L==L_alrevez){true;} //o return L==L_alrevez;
}
*/
int main(int argc, char *argv[]) {
	char predicado[] = "alli si maria avisa y asi va a ir a mi silla";	
	
	cout << "Predicado: " << predicado << endl;
	
	bool z = is_palindromoJA(predicado);
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





