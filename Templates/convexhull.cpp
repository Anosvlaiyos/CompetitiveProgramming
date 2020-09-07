#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll dot(pll a,pll b){return a.first*b.first+a.second*b.second;}
ll cross(pll a,pll b){return a.first*b.second-a.second*b.first;}
bool ccw(pll a,pll b,pll c){return cross({b.first-a.first,b.second-a.second},{c.first-b.first,c.second-b.second})>0;}
vector<pll> cvxhull(vector<pll> p){
	int n=p.size();
	sort(p.begin(),p.end());
	vector<pll>cvx,cvx2;
	for (int i = 0; i<n; i++) {
		while(cvx.size()>=2&&!ccw(cvx[cvx.size()-2],cvx.back(),p[i]))cvx.pop_back();
		cvx.push_back(p[i]);
	}
	cvx2.push_back(cvx.back());
	for (int i = n - 2; i >= 0; i--) {
		while(cvx2.size()>=2&&!ccw(cvx2[cvx2.size()-2],cvx2.back(),p[i]))cvx2.pop_back();
		cvx2.push_back(p[i]);
	}
	for(int i=1;i+1<cvx2.size();i++)cvx.push_back(cvx2[i]);
	for(auto e:cvx)cerr<<e.first<<" "<<e.second<<"\n";
	cerr<<"\n";
	return cvx;
}
