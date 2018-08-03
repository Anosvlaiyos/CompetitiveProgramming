#include <bits/stdc++.h>
#define pi 3.14159265358979
using namespace std;
int rev(int t, int n) {
	int i, q = 0;
	for (i = 0; i<n; i++)q |= ((t >> i) & 1) << n - 1 - i;
	return q;
}
void ord(complex<double> *ar, int n) {
	int r;
	complex<double> *t = new complex<double>[1 << n];
	for (int i = 0; i<1 << n; i++)t[rev(i, n)] = ar[i];
	for (int i = 0; i < 1 << n; i++)ar[i] = t[i];
	delete t;
}
void fft(complex<double> *ar, int n, bool inv = 0) {
	int N = 1 << n, i, j, k, mod = N - 1;
	long long sc = 1 << n - 1;
	complex<double> *w = new complex<double>[N], aa, bb;
	ord(ar, n);
	for (i = 0; i<N; i++)w[i] = polar(1., (inv ? 1 : -1)* 2.*i*pi / N);
	for (i = 0; i<n; i++, sc >>= 1) {
		for (j = 0; j<N; j++) {
			if (j&(1 << i))continue;
			k = j | (1 << i);
			aa = ar[j] + ar[k] * w[(sc*j)&mod];
			bb = ar[j] + ar[k] * w[(sc*k)&mod];
			ar[j] = aa;
			ar[k] = bb;
		}
	}
	if (inv)for (i = 0; i<N; i++)ar[i] /= N;
	delete w;
}