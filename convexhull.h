#include "stdafx.h"
#define scanf scanf_s
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
pii p[4000];
vector<pii> cvx;
bool ccw(pii a, pii b, pii c) {
	return a.fi*b.se + b.fi*c.se + c.fi*a.se - b.fi*a.se - c.fi*b.se - a.fi*c.se>0;
}
int main() {
	int n, i,j;
	scanf("%d", &n);
	for (i = 0; i<n; i++)scanf("%d%d", &(p[i].fi), &(p[i].se));
	sort(p, p + n);
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
	for (i = n - 3; i >= 1; i--) {
		while (!ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], p[i])) {
			cvx.pop_back(); if (cvx.size() == idek)break;
		}
		cvx.push_back(p[i]);
	}
}