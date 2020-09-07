#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FFT{
    typedef complex<double>C;
    const double PI=acos(-1);
    vector<int>ord;
    vector<C>w={0,1};
    void getroots(int n){
        if(w.size()>=n)return;
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
    vector<ll> convolve(vector<ll>a, vector<ll>b){
        int n=a.size()+b.size()-1;
        n=1<<32-__builtin_clz(n-1);
        vector<C>c(n);
        for(int i=0;i<a.size();i++)c[i].real(a[i]);
        for(int i=0;i<b.size();i++)c[i].imag(b[i]);
        fft(c);
        for(int i=0;i<n;i++)c[i]*=c[i]*(0.5/n);
        reverse(c.begin()+1,c.end());
        fft(c);
        vector<ll>ans(a.size()+b.size()-1);
        for(int i=0;i<ans.size();i++)ans[i]=c[i].imag()+.5;
        return ans;
    }
};