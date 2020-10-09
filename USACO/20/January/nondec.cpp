#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);
typedef array<int,20>vec;
typedef array<vec,20>mat;
vec mult(mat a,vec b){
    vec c={0};
    for(int i=0;i<20;i++)for(int j=0;j<20;j++)c[i]=(c[i]+ll(a[i][j])*b[j])%mod;
    return c;
}
mat adv(mat a,int x){
    for(int j=0;j<20;j++){
        a[x][j]=(a[x][j]*2)%mod;
        for(int i=0;i<x;i++)a[x][j]=(a[x][j]+a[i][j])%mod;
    }
    return a;
}
mat bac(mat a,int x){
    for(int i=0;i<20;i++){
        for(int j=0;j<=x;j++)a[i][j]=(a[i][j]-half*a[i][x])%mod;
    }
    return a;
}
mat A[50001],B[50001];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    freopen("nondec.in","r",stdin);
    freopen("nondec.out","w",stdout);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    vec a;
    int n,k;
    cin>>n>>k;
    A[0]={0};
    for(int i=0;i<20;i++)A[0][i][i]=1;
    B[0]=A[0];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        A[i]=adv(A[i-1],x-1);
        B[i]=bac(B[i-1],x-1);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        vec ans={0};
        ans[0]=1;
        ans=mult(A[r],mult(B[l-1],ans));
        int res=0;
        for(int i=0;i<20;i++)res=(res+ans[i])%mod;
        if(res<0)res+=mod;
        printf("%d\n",res);
    }
}