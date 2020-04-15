#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e3+10;
const ll mod=1e9+7;
vector<int>g[mn];
ll cap[mn][mn],ind[mn],dep[mn];
const ll inf=0x3f3f3f3f3f3f3f3f;
void add_edge(int a,int b,ll c){
    g[a].push_back(b);
    g[b].push_back(a);
    cap[a][b]=c;
}
ll dfs(int x,int n,ll big){
    if(n==x)return big;
    for(;ind[x]<g[x].size();ind[x]++){
        int y=g[x][ind[x]];
        if(dep[y]!=dep[x]+1||cap[x][y]<=0)continue;
        ll v=dfs(y,n,min(big,cap[x][y]));
        if(v){
            cap[x][y]-=v;
            cap[y][x]+=v;
            return v;
        }
    }
    return 0;
}
bool bfs(int n){
    memset(dep,0x3f,sizeof(dep));
    memset(ind,0,sizeof(ind));
    dep[0]=0;
    queue<int>q;
    q.push(0);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int y:g[x]){
            if(dep[y]==inf&&cap[x][y]>0)dep[y]=dep[x]+1,q.push(y);
        }
    }
    return dep[n]!=inf;
}
ll maxflow(int n){
    ll ans=0;
    while(bfs(n)){
        ll d=-1;
        while(d){
            ans+=(d=dfs(0,n,inf));
        }
    }
    return ans;
}
