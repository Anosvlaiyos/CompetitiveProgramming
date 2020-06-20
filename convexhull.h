#include<bits/stdc++.h>
using namespace std;
vector<pll> cvxhull(vector<pll> p){
	sort(p.begin(),p.end());
	cvx.push_back(p[0]);
	cvx.push_back(p[1]);
	for (i = 2; i<n; i++) {
		while (!ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], p[i])) {
			cvx.pop_back(); if (cvx.size() == 1)break;
		}
		cvx.push_back(p[i]);
	}
	int idek = cvx.size();
	cvx.push_back(p[n - 2]);
	for (i = n - 3; i >= 0; i--) {
		while (!ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], p[i])) {
			cvx.pop_back(); if (cvx.size() == idek)break;
		}
		cvx.push_back(p[i]);
	}
	cvx.pop_back();
	return cvx;
}
