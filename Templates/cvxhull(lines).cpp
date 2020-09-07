#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct l{
  ll m,b,le=-0x3f3f3f3f;
  l(ll a,ll z){m=a;b=z;}
};
int th[100000];
vector<l> cvx;
bool die(l a,l b,l c){
    return (a.b-b.b)/(b.m-a.m)>(b.b-c.b)/(c.m-b.m);
}
void push(l a){
    while(cvx.size()>=2&&die(cvx[cvx.size()-2],cvx[cvx.size()-1],a))cvx.pop_back();
    if(cvx.size())a.l=(a.b-cvx[cvx.size()-1].b)/(cvx[cvx.size()-1].m-a.m)+1;
    cvx.push_back(a);
}
int query(ll x){
    int cur=0;
	for (int i = 1 << 21; i; i >>= 1)if (cur + i < cvx.size() && cvx[cur + i].le <= x)cur+=i;
    return cvx[cur].m*x+cvx[cur].b;
}








bool die(line a, line b, line c) {
	return (a.b - b.b) / (b.m - a.m) >= (b.b - c.b) / (c.m - b.m);
}
struct cvx {
	vector<line> v;
	void insert(line l) {
		while (v.size() >= 2 && die(v[v.size() - 2], v[v.size() - 1], l))v.pop_back();
		if(cvx.size())l.l = (l.b - v[v.size() - 1].b) / (v[v.size() - 1].m - l.m);
		v.push_back(l);
	}
	double query(double x) {
		int cur = 0,i;
		for (i = 1 << 21; i; i >>= 1)if (cur + i < v.size() && v[cur + i].l <= x)cur += i;
		return v[cur].m*x + v[cur].b;
	}
};
