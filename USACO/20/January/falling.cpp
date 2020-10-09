#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
inline ll gcd(ll a,ll b){while(b)a%=b,swap(a,b);return a;}
deque<pll>cvx;
ll b[mn];
int q[mn];
ll ansa[mn],ansb[mn];
bool bad(pll a,pll b,pll c){
    return (b.second-a.second)*(a.first-c.first)>(c.second-a.second)*(a.first-b.first);
}
int o[mn];
int main(){
    freopen("falling.in","r",stdin);
    freopen("falling.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",b+i);
    for(int i=1;i<=n;i++)scanf("%d",q+i);
    for(int i=1;i<=n;i++)o[i]=i;
    sort(o+1,o+1+n,[](int x,int y){return b[x]>b[y];});
    for(int i=1;i<=n;i++){
        ll m=o[i];
        while(cvx.size()&&(-m<cvx[0].first||(cvx.size()>=2&&bad({-m,b[m]},cvx[0],cvx[1]))))cvx.pop_front();
        cvx.push_front({-m,b[m]});
        if(b[q[m]]>b[m])continue;
        int cur=-1;
        for(int i=1<<17;i;i>>=1){
            if(cur+i+1>=cvx.size());
            else if(cvx[cur+i].first>-q[m])cur+=i;
            else if(bad({-q[m],b[q[m]]},cvx[cur+i],cvx[cur+i+1]))cur+=i;
        }
        cur++;
        ll a=(cvx[cur].second-b[q[m]]);
        ll b=-q[m]-cvx[cur].first;
        if(b<0)ansa[m]=-1,ansb[m]=1;
        else{
            ll g=gcd(a,b);
            ansa[m]=a/g,ansb[m]=b/g;
        }
    }
    cvx.clear();
    reverse(o+1,o+1+n);
    for(int i=1;i<=n;i++){
        ll m=o[i];
        while(cvx.size()&&(m<cvx[0].first||(cvx.size()>=2&&bad({m,-b[m]},cvx[0],cvx[1]))))cvx.pop_front();
        cvx.push_front({m,-b[m]});
        if(-b[q[m]]>-b[m])continue;
        int cur=-1;
        for(int i=1<<17;i;i>>=1){
            if(cur+i+1>=cvx.size());
            else if(cvx[cur+i].first>q[m])cur+=i;
            else if(bad({q[m],-b[q[m]]},cvx[cur+i],cvx[cur+i+1]))cur+=i;
        }
        cur++;
        ll a=(cvx[cur].second+b[q[m]]);
        ll b=q[m]-cvx[cur].first;
        if(b<0)ansa[m]=-1,ansb[m]=1;
        else{
            ll g=gcd(a,b);
            ansa[m]=a/g,ansb[m]=b/g;
        }
    }
    for(int i=1;i<=n;i++){
        if(ansa[i]==-1)printf("-1\n");
        else printf("%lld/%lld\n",ansa[i],ansb[i]);
    }
}