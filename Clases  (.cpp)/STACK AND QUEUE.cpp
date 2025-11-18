
typename<class T>
class stack::private list<T>{
	int sizem;
public:
	stack():sizem(0){}
	void clear(){erase(begin(),end());sizem=0}
	bool empty(){return sizem==0;}
	T &top(){return *begin();}
	void pop(){erase(begin());sizem--;}
	void push(T x){insert(end(),x);sizem++;}
	int size(){return sizem;}
};

typename<class T>
class queue::private list<T>{
	int sizem;
public:
	stack():sizem(0){}
	void clear(){erase(begin(),end());sizem=0}
	bool empty(){return sizem==0;}
	T &front(){return *begin();}
	void pop(){erase(begin());sizem--;}
	void push(T x){insert(end(),x);sizem++;}
	int size(){return sizem;}
};
	




