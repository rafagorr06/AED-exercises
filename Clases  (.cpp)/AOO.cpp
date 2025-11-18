
class cell{
	friend class tree;
	friend class iterator_t;
	elem_t elem;
	cell *right,*left_child;
	cell():right(NULL),left_child(NULL){}
};

class iterator_t{
	friend class tree;
	cell *ptr,*prev,*father;
	iterator_t(cell *p,cell *prev_a, cell *f_a):ptr(p),prev(prev_a),father(f_a){}
public:
	iterator_t(const iterator_t &p){
		ptr=p.ptr;
		prev=p.prev;
		father=p.father;
	}
	bool operator!=(iterator_t p){
		return ptr!=p.ptr;
	}
	bool operator==(iterator_t p){
		return ptr==p.ptr;
	}
	iterator_t():ptr(NULL),prev(NULL),father(NULL){}
	iterator_t right(){return iterator_t(ptr->right,R,father);}
	iterator_t lchild(){return iterator_t(ptr->left_child,NULL,ptr);}
};

class tree{
	cell *header;
public:
	tree(){
		header=new cell;
		header->right=NULL;
		header->left_child=NULL;
	}
	~tree(){clear();delete header;}
	
	iterator_t insert(iterator_t p, elem_t j){
		assert(!(p.father==header &&p.ptr ));
		cell *c=new cell;
		c->right=p.ptr;
		c->elem=j;
		if(p.prev)p.prev->right=c;
		else p.father->left_child=c;
		return p;
	}
	
	elem_t retrieve (iterator_t p){return p.ptr->elem;}
	
	iterator_t find(elem_t j){return find(j,begin());}
	
	iterator_t find(iterator_t p, elem_t j){
		if(p==end()||retrieve(p)==j)return p;
		iterator_t q,c = p.lchild(); 
		while(c!=end()){
			q=find(j,c);
			if(q!=end())return q;
			else c=c.right();
		}
		return iterator_t();
	}
	
	void clear(){erase(begin());}
	iterator_t begin(){return iterator_t(header->left_child,NULL,header);}
	iterator_t end(){return iterator_t();}
	
	iterator_t erase(iterator_t p){
		if(p==end())return p;
		iterator_t c = p.lchild();
		while(c!=end()) c=erase(c);
		cell *q = p.ptr;
		p.ptr=p.ptr->right;
		if(p.prev) p.prev->right=p.ptr;
		else p.father->left_child=p.ptr;
		delete q;
		return p;
	}
		
	iterator_t splice(iterator_t to, iterator_t from){
		assert(!(to.father==header&&to.ptr));
		if(from->right==to.ptr) return from;
		cell *c=from.ptr;
		if(from.prev)from.prev->right=c;
		else from.father->left_child=c;
		c->right=to.ptr;
		to.ptr=c;
		if(to.prev)to.prev->right=c;
		else to.father->left_child=c;
		return to;
	}
	
};






