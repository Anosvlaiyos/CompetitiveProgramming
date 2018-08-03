#define pri1 2013265921LL
#define pri2 1811939329LL
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b,ll mod) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a%mod)if (b & 1)ans = ans * a%mod;
	return ans;
}
int rev(int t, int n) {
	int i, q = 0;
	for (i = 0; i<n; i++)q |= ((t >> i) & 1) << n - 1 - i;
	return q;
}
void ord(ll *ar, int n) {
	int r;
	ll *t=new ll[1<<n];
	for (int i = 0; i<1 << n ; i++)t[rev(i,n)] = ar[i];
	for (int i = 0; i < 1 << n; i++)ar[i] = t[i];
	delete t;
}
void fft(ll *ar, int n, bool inv = 0,ll mod=pri1) {
	int N = 1 << n, i, j,k,m=N-1;
	long long sc = 1 << n - 1;
	ll *w = new ll[N], aa, bb,id;
	for (i = 2; pow(i, mod >> 1, mod) == 1; i++);
	ord(ar, n);
	w[0] = 1, w[1] = pow(i, mod >> n,mod);
	for (i = 2; i < N; i++)w[i] = w[i - 1] * w[1] % mod;
	if (inv)for (i = 1; i*2 < N; i++)w[i] ^= w[N - i] ^= w[i] ^= w[N - i];
	for (i = 0; i<n; i++,sc>>=1) {
		for (j = 0; j<N; j++) {
			if (j&(1 << i))continue;
			k = j | (1 << i);
			aa = ar[j] + ar[k] * w[(sc*j)&m];
			bb = ar[j] + ar[k] * w[(sc*k)&m];
			ar[j] = aa%mod;
			ar[k] = bb%mod;
		}
	}
	ll q = pow(N,mod-2,mod);
	if (inv)for (i = 0; i < N; i++)ar[i] =ar[i]* q%mod;
	delete w;
}
ll a[1<<2],b[1<<2],c[1<<2];
int main()
{
	a[0] = 2, a[1] = 3,b[0]=2,b[1]=3;
	fft(a, 2);
	fft(b, 2);
	for (int i = 0; i < 1<<2; i++)c[i] = a[i] * b[i]%pri1;
	fft(c, 2,1);
}