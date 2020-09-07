int exgcd(int a, int b, int *x, int *y,int mod=1000000007) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int xx, yy;
	int gcd=exgcd(b, a%b, &xx, &yy,mod);
	*x = yy;
	*y = (xx - a / b * yy)%mod;
	return gcd;
}
int inv(int a, int mod) {
	int x, y;
	exgcd(a, mod, &x, &y, mod);
	return (x + mod) % mod;
}