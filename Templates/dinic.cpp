#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct dinic{
    int n;
    T inf;
    struct E{
        int to,rev;
        T cap;
    };
    vector<vector<E>>g;
    vector<int>at,dep;
    dinic(int n,T inf=LLONG_MAX){
        this->n=n;
        this->inf=inf;
        g.resize(n);
        at.resize(n);
        dep.resize(n);
    }
    void addEdge(int x,int y,T c){
        g[x].push_back({y,g[y].size(),c});
        g[y].push_back({x,g[x].size()-1,0});
    }
    int s,t;
    bool bfs(){
        queue<int>q;
        q.push(s);
        fill(dep.begin(),dep.end(),-1);
        dep[s]=0;
        while(q.size()){
            int x=q.front();
            q.pop();
            for(E e:g[x])if(dep[e.to]==-1&&e.cap>0){
                dep[e.to]=dep[x]+1;
                q.push(e.to);
            }
        }
        return dep[t]!=-1;
    }
    T dfs(int x,T cap){
        if(x==t)return cap;
        for(;at[x]<g[x].size();at[x]++){
            E e=g[x][at[x]];
            if(e.cap<=0||dep[e.to]!=dep[x]+1)continue;
            T v=dfs(e.to,min(cap,e.cap));
            if(v){
                g[x][at[x]].cap-=v;
                g[e.to][e.rev].cap+=v;
                return v;
            }
        }
        return 0;
    }
    T maxflow(int s,int t){
        this->s=s,this->t=t;
        T ans=0;
        while(bfs()){
            fill(at.begin(),at.end(),0);
            T v;
            do{
                ans+=(v=dfs(s,inf));
            }while(v>0);
        }
        return ans;
    }
};
