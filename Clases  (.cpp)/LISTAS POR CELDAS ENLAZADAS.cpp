
//implementacion de listas por celdas enlazadas

class cell{
	friend class list;
	elem_t elem;
	cell *next;
	cell() : next(NULL){}
};

class cell;
typedef cell *iterator_t;

class list{
private:
	cell *first, *last;
public:
	list() : first(new cell), last(first){
		first->next = NULL;
	}
	
	list::~list(){
		clear();
		delete first;
	}

	elem_t &list::retrieve(iterator_t p){
		return p->next->elem;
	}
	
	iterator_t list::next(iterator_t p){
		return p->next;
	}
	
	iterator_t prev(iterator_t p){
		iterator_t q = first;
		while(q->next != p) q = q->next;
		return q;
	}
	
	iterator_t list::insert(iterator_t p, elem_t j){
		iterator_t q = p->next;
		iterator_t c = new cell;
		p->next = c;
		c->next = q;
		c->elem = j;
		if(q==NULL) last = c;
		return p;
	}
	
	iterator_t erase(iterator_t p){
		if(p->next==last) last=p;
		iterator_t q = p->next;
		p->next = q->next;
		delete q;
		return p;
	}
	
	iterator_t erase(iterator_t p, iterator_t q){
		if(p==q) return p;
		iterator_t s, r = p->next;
		p->next = q->next;
		if(!p->next) last = p;
		while(r!=q->next){
			s=r->next;
			delete r;
			r=s;
		}
		return p;
	}
	
	void clear(){
		erase(begin(),end());
	}
	iterator_t begin(){
		return first;
	}
	
	iterator_t end(){
		return last;
	}

	void list::print() {
		iterator_t p = begin();
		while (p!=end()) {
			cout << retrieve(p) << " ";
			p = next(p);
			}
		cout << endl;
	}

	int size();

}; 


