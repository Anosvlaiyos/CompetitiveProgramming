struct node {
	int v, s,p;
	node *l, *r;
};
typedef node* pnode;
pnode treap;
int sz(pnode t) { return t ? t->s : 0; }
void updsz(pnode t) { if (t)t->s = sz(t->l) + sz(t->r) + 1; }
void split(pnode t, pnode &l, pnode &r, int a) {
	if (!t)l = r = NULL;
	else if (a > t->v) { l = t; split(t->r, l->r, r, a); }
	else { r = t; split(t->l, l, r->l, a); }
	updsz(t);
}
void merge(pnode &t, pnode l, pnode r) {
	if (!l || !r)t=l ? l : r;
	else if (l->p > r->p) { t = l; merge(t->r, l->r, r); }
	else { t = r; merge(t->l, l, r->l); }
	updsz(t);
}
void insert(pnode &t, pnode x) {
	if (!t)t = x;
	else if (x->p > t->p) { split(t, x->l, x->r, x->v); t = x; }
	else if (x->v < t->v)insert(t->l, x);
	else insert(t->r, x);
	updsz(t);
}
void erase(pnode &t, int x) {
	if (!t)return;
	if (t->v == x) { pnode a; merge(a, t->l, t->r); t = a; }
	else if (x > t->v)erase(t->r, x);
	else erase(t->l, x);
	updsz(t);
}
int order(pnode t, int x) {
	if (!t)return 0;
	else if (x < t->v)return order(t->l, x);
	else return sz(t->l) + 1 + order(t->r, x);
}
int at(pnode t, int x) {
	if (x == sz(t->l))return t->v;
	else if (x < sz(t->l))return at(t->l,x);
	else return at(t->r, x - sz(t->l) - 1);
}
pnode init(int v=0x3f3f3f3f) {
	pnode p = new node();
	p->v = v, p->p = rand();
	return p;
}
//This is a treap acting as a balanced binary search tree that can answer queries and insert values in O(log N) time.
