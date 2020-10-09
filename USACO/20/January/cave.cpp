#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
typedef pair<int,int>pii;
struct uf{
    int p[1010];
    uf(){for(int i=0;i<1010;i++)p[i]=i;}
    int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
    void u(int a,int b){p[f(a)]=f(b);}
};
uf dsu[1010];
ll dp[1010][1010];
string s[1010];
const ll mod=1e9+7;
vector<int> gr[1010];
int main(){
    freopen("cave.in","r",stdin);
    freopen("cave.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=n-1;i>=0;i--)cin>>s[i];
    n-=2,m-=2;
    for(int i=1;i<=m;i++){
        if(s[1][i]==s[1][i+1]&&s[1][i]=='.')dsu[1].u(i,i+1);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=1;
    for(int i=1;i<=m;i++)if(dsu[1].f(i)==i)dp[1][i]=(s[1][i]=='.')?2:1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==s[i][j+1]&&s[i][j]=='.')dsu[i].u(j,j+1);
            gr[j].clear();
        }
        for(int j=1;j<=m;j++)if(s[i][j]=='.')gr[dsu[i-1].f(j)].push_back(j);
        for(int j=1;j<=m;j++)for(int k=0;k+1<gr[j].size();k++)dsu[i].u(gr[j][k],gr[j][k+1]);
        for(int j=1;j<=m;j++)if(s[i][j]=='.'&&s[i-1][j]=='.'){
            dp[i][dsu[i].f(j)]*=dp[i-1][dsu[i-1].f(j)];
            dp[i-1][dsu[i-1].f(j)]=1;
            dp[i][dsu[i].f(j)]%=mod;
        }
        for(int j=1;j<=m;j++)if(dsu[i].f(j)==j&&s[i][j]=='.')dp[i][j]++;
    }
    ll ans=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(dsu[i].f(j)==j)ans*=dp[i][j],ans%=mod;
    printf("%lld",ans);
}