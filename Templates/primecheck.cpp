#include <bits/stdc++.h>
using namespace std;
typedef __int128 iint;
typedef unsigned long long ull;
iint p(iint a, ull b, ull mod) {
	if (b == 1)return a%mod;
	iint h = p(a, b / 2, mod);
	h = h * h%mod;
	if (b % 2)h = h * a%mod;
	return h;
}
bool check(iint r, ull n) {
	int s = 0;
	ull k = n - 1;
	while (!(k & 1)) { k >>= 1; s++; }
	iint a = p(r, k, n);
	if (a == 1)return 1;
	for (; s != 0; s--, a = a * a%n) {
		if (a == 1)return 0;
		if (a == n-1)return 1;
	}
	return 0;
}
bool prime(ull n) {
	if (n == 1)return 0;
	ull s = 0;
	for (int i = 0; i<50; i++) {
		iint r =rand()%n;
		while(r==0)r=rand()%n;
		if (!check(r, n))return 0;
	}
	return 1;
}