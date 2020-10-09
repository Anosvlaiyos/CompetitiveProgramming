#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5e5+10;
typedef pair<ll,ll>pll;
int mo[mn];
int lim;
bool gud=1;
vector<int>g[mn];
void dfs(int x,int p){
    multiset<int>v,inf,f;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        if(mo[y]+1<lim)v.insert(mo[y]+1);
        else inf.insert(mo[y]+1);
    }
    if(!v.size()&&!inf.size())return;
    while(v.size()>1){
        int l=*v.begin();
        auto it=v.lower_bound(lim-l);
        if(it!=v.end()){
            if(it==v.begin())++it;
            v.erase(it);
            v.erase(v.begin());
        }
        else{
            f.insert(*v.begin());
            v.erase(v.begin());
        }
    }
    if(v.size())f.insert(*v.begin());
    if(f.size()>inf.size()+1){
        gud=0;
        return;
    }
    if(inf.size()>f.size()){
        mo[x]=lim;
        return;
    }
    if(f.size())mo[x]=*--f.end();
    if(f.size()>inf.size()&&x==1)gud=0;
}
int main(){
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cur=0;
    for(int i=1<<16;i;i>>=1){
        memset(mo,0,sizeof(mo));
        lim=cur+i;
        gud=1;
        dfs(1,0);
        if(gud)cur+=i;
    }
    if(n==1){
        printf("0");
        return 0;
    }
    else printf("%d",cur);

}