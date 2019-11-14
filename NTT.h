#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
vector<int>ord;
vector<ll>w;
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
void getroots(int n){
    if(w.size()>=n)return;
    if(w.empty())w={0,1};
    int len=w.size();
    w.resize(n);
    for(;len<n;len<<=1){
        ll mult=po(2,(mod-1)/(2*len));
        w[len]=1;
        for(int i=1;i<len;i++)w[i+len]=w[i+len-1]*mult%mod;
    }
}
void reorder(vector<ll>&a) {
    int n = a.size();
    if (ord.size() != n) {
        ord.assign(n, 0);
        int len = __builtin_ctz(n);
        for (int i = 0; i < n; i++)ord[i] = (ord[i >> 1] >> 1) | ((i & 1) << len - 1);
    }
    for (int i = 0; i < n; i++)if (i < ord[i])swap(a[i], a[ord[i]]);
}
void fft(vector<ll>&a){
    int n=a.size();
    getroots(n),reorder(a);
    for(int len=1;len<n;len<<=1)for(int i=0;i<n;i+=len<<1)for(int j=0;j<len;j++){
        ll u=a[i+j],v=[i+j+len]*w[j+len];
        a[i+j]=(u+v)%mod,a[i+j+len]=(u-v)%mod;
    }
}
