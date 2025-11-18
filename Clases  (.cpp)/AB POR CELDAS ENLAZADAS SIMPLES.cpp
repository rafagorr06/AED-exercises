//AB CON CELDAS ENLAZADAS SIMPLES

class cell{
	friend class btree;
	friend class iterator_t;
	elem_t elem;
	cell *right,*left;
	cell():right(NULL),left(NULL);
};

class iterator_t{
	friend class btree;
	cell *ptr,*father;
	side_t side;
	enum side_t {NONE,R,L}
	iterator_t(cell *p, side_t side_a,cell *f_a):ptr(p),side(side_a),father(f_a){}
public:
	iterator(const iterator_t &p){
		ptr=p.ptr;
		side=p.side;
		father=p.father;
	}
	bool operator!=(iterator_t p){ return ptr!=p.ptr; }
	bool operator==(iterator_t p){ return ptr==p.ptr; }
	iterator_t():ptr(NULL),side(NONE),father(NULL);
	iterator_t left(){ return iterator_t(ptr->left,L,ptr);}
	iterator_t right(){ return iterator_t(ptr->right,R,ptr);}
};

class btree{
	cell *header;
	iterator_t tree_copy_aux(iterator_t nq, btree &TT,iterator_t nt){...}
public:
	static int cell_count_m;
	static int cell_count(){return cell_count_m;}
	btree(){
		header=new cell;
		cell_count_m++;
		header->right=NULL;
		header->left=NULL;
	}
	
	iterator_t insert(iterator_t p,elem_t j){
		cell_count_m++;
		cell *c=new cell;
		c->j=j;
		if(p.side==iterator_t::R)p.father->right=c;
		else p.father->left=c;
		p.ptr=c;
		return p;
	}
	void clear(){erase(begin());}
	iterator_t begin(){return iterator_t(header->left,iterator_t::L,header);}
	iterator_t end(){return iterator_t();}
	
	iterator_t splice(iterator_t to,iterator_t from){
		cell *c=from.ptr;
		from.ptr=NULL;
		if(from.side==iterator_t::R)from.father->right=NULL;
		else from.father->left=NULL;
		if(to.side==iterator_t::R)to.father->right=c;
		else to.father->left=c;
		to.ptr=c;
		return to;
	}
};







