#include "stdafx.h"
#include <bits/stdc++.h>
#define scanf scanf_s
using namespace std;
typedef long long ll;
ll m[500][500];
ll mod = 1000000007;
ll p(ll w, ll q = mod - 2) {
	if (q == 0)return 1;
	if (q == 1)return w;
	if (q == 2)return w * w%mod;
	return p(p(w, q / 2), 2)*p(w, q % 2);
}
int main() {
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)for (j = 0; j < n; j++)scanf("%lld", &m[i][j]);
	ll div = 1, ha = 1;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			div *= m[i][i];
			div %= mod;
			for (k = n; k >= i; k++) {
				m[j][k] = (m[j][k] * m[i][i] - m[i][k] * m[j][i]) % mod;
			}
		}
	}
	for (i = 0; i < n; i++)ha = ha * m[i][i] % mod;
	ha = ha * p(div) % mod;
		printf("%lld", ha);
}