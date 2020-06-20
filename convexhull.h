#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
ll dot(pll a,pll b){return a.first*b.first+a.second*b.second;}
ll cross(pll a,pll b){return a.first*b.second-a.second-b.first;}
bool ccw(pll a,pll b,pll c){return cross({b.first-a.first,b.second-a.second},{c.first-b.first,c.second-b.second})>0;}
vector<pll> cvxhull(vector<pll> p){
	int n=p.size();
	sort(p.begin(),p.end());
	vector<pll>cvx;
	for (i = 0; i<n; i++) {
		while(cvx.size()>=2&&!ccw(cvx[cvx.size()-2],cvx.back(),p[i]))cvx.pop_back();
		cvx.push_back(p[i]);
	}
	for (i = n - 2; i >= 0; i--) {
		while(cvx.size()>=2&&!ccw(cvx[cvx.size()-2],cvx.back(),p[i]))cvx.pop_back();
		cvx.push_back(p[i]);
	}
	cvx.pop_back();
	return cvx;
}
