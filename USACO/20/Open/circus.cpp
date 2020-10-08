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
vector<pii>g[mn];
bool ded[mn];
int p[mn],s[mn],nb[mn];
set<int>av;
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void mer(int a,int b,int v=1){
    a=f(a),b=f(b);
    if(a==b)return;
    av.erase(b);
    p[b]=a;
    s[a]+=s[b]+v-1;
    nb[a]+=nb[b]-2;
}
struct edge{
    int a,b,v;
};
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll fact[mn],ifact[mn];
ll pr[mn];
int main(){
    #ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #else
    freopen("circus.in","r",stdin);
    freopen("circus.out","w",stdout);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n;
    fact[0]=ifact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod,ifact[i]=po(fact[i]);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }
    vector<int>kil;
    for(int i=1;i<=n;i++)if(g[i].size()==2)kil.push_back(i);
    for(int i:kil){
        ded[i]=1;
        vector<pii>v;
        for(pii p:g[i])if(!ded[p.first])v.push_back(p);
        g[v[0].first].push_back({v[1].first,v[0].second+v[1].second});
        g[v[1].first].push_back({v[0].first,v[0].second+v[1].second});
    }
    vector<edge>ed;
    for(int i=1;i<=n;i++)if(!ded[i])for(pii p:g[i])if(i<p.first&&!ded[p.first]){
        ed.push_back({i,p.first,p.second});
        nb[i]++,nb[p.first]++;
    }
    sort(ed.begin(),ed.end(),[](edge a,edge b){return a.v<b.v;});
    fill(s,s+mn,1);
    iota(p,p+mn,0);
    for(int i=1;i<=n;i++)if(!ded[i])av.insert(i);
    for(int i=n-1,j=0;i>=1;i--){
        ll cur=1;
        while(j!=ed.size()&&i==n-ed[j].v-2)mer(ed[j].a,ed[j].b,ed[j].v),j++;
        for(int x:av){
            cur*=ifact[(nb[x]-1)*(n-i-1)+s[x]-1],cur%=mod;
            //cerr<<(nb[x]-1)*(n-i-1)+s[x]-1<<' ';
            //cerr<<s[x]<<' '<<nb[x]<<endl;
        }
        //cerr<<j<<endl;
        pr[i]=fact[i]*cur%mod;
    }
    pr[n]=fact[n];
    for(int i=1;i<=n;i++)printf("%lld\n",pr[i]);
}