#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double>C;
const double PI=acos(-1);
vector<int>ord;
vector<C>w;
void getroots(int n){
    if(w.size()>=n)return;
    if(w.empty())w={{0,0},{1,0}};
    int len=w.size();
    w.resize(n);
    for(;len<n;len<<=1){
        double ang=PI/len;
        for(int i=0;i<len;i++){
            if(i&1)w[i+len]=polar(1.,i*ang);
            else w[i+len]=w[(i+len)>>1];
        }
    }
}
void reorder(vector<C>&a){
    int n=a.size();
    if(ord.size()!=n){
        ord.assign(n,0);
        int len=__builtin_ctz(n);
        for(int i=0;i<n;i++)ord[i]=(ord[i>>1]>>1)|((i&1)<<len-1);
    }
    for(int i=0;i<n;i++)if(i<ord[i])swap(a[i],a[ord[i]]);
}
void fft(vector<C>&a){
    int n=a.size();
    getroots(n),reorder(a);
    for(int len=1;len<n;len<<=1)for(int i=0;i<n;i+=len<<1)for(int j=0;j<len;j++){
        C u=a[i+j],v=a[i+j+len]*w[j+len];
        a[i+j]=u+v,a[i+j+len]=u-v;
    }
}
