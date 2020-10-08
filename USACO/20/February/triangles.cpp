#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const double PI=acos(-1);
ll ch[11][11];
array<ll,11>zero;
array<ll,11> advance(array<ll,11>v){
    array<ll,11>w=zero;
    for(int i=0;i<11;i++){
        for(int j=0;j<=i;j++){
            w[i]+=ch[i][j]*v[j],w[i]%=mod;
        }
    }
    return w;
}
array<ll,11> add(array<ll,11>a,array<ll,11>b){
    array<ll,11>c;
    for(int i=0;i<11;i++)c[i]=(a[i]+b[i])%mod;
    return c;
}
array<ll,11> mult(array<ll,11>a,ll b){
    array<ll,11>c;
    for(int i=0;i<11;i++)c[i]=a[i]*b%mod;
    return c;
}
array<ll,11>seg[mn*4];
ll laz[mn*4];
#define mid ((l+r)>>1)
void prop(int x){
    if(laz[x]==1)return;
    seg[x]=mult(seg[x],laz[x]);
    if(x*2+1<mn*4){
        laz[x*2]*=laz[x],laz[x*2]%=mod;
        laz[x*2+1]*=laz[x],laz[x*2+1]%=mod;
    }
    laz[x]=1;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=add(seg[x*2],seg[x*2+1]);
}
void mul(int x,int l,int r,int a,int b){
    if(a>b)return;
    if(l==a&&r==b)laz[x]*=2,laz[x]%=mod;
    else{
        prop(x);
        if(b<=mid)mul(x*2,l,mid,a,b);
        else if(a>mid)mul(x*2+1,mid+1,r,a,b);
        else mul(x*2,l,mid,a,mid),mul(x*2+1,mid+1,r,mid+1,b);
        eval(x);
    }
}
void upd(int x,int l,int r,int a,array<ll,11>b){
    prop(x);
    if(l==r)seg[x]=add(seg[x],b);
    else{
        if(a<=mid)upd(x*2,l,mid,a,b);
        else upd(x*2+1,mid+1,r,a,b);
        eval(x);
    }
}
array<ll,11> query(int x,int l,int r,int a,int b){
    if(a>b)return zero;
    prop(x);
    if(l==a&&r==b)return seg[x];
    else if(b<=mid)return query(x*2,l,mid,a,b);
    else if(a>mid)return query(x*2+1,mid+1,r,a,b);
    else return add(query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b));
}
int pt[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    freopen("help.in","r",stdin);
    freopen("help.out","w",stdout);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    ch[0][0]=1;
    for(int i=1;i<=10;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
    }
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pt[a]=b;
    }
    for(int i=0;i<11;i++)zero[i]=0;
    fill(laz,laz+mn*4,1);
    array<ll,11>ini=zero;
    ini[0]=1;
    upd(1,0,2*n,0,ini);
    for(int i=1;i<=2*n;i++)if(pt[i]){
            array<ll,11>a,b;
            a=advance(query(1,0,2*n,0,i));
            b=query(1,0,2*n,i,pt[i]);
            upd(1,0,2*n,pt[i],add(a,b));
            mul(1,0,2*n,pt[i]+1,2*n);
            //cerr<<"check"<<i<<endl;
        }
    //cerr<<"almost"<<endl;
    array<ll,11>ans=query(1,0,2*n,0,2*n);
    printf("%lld",ans[k]);
}