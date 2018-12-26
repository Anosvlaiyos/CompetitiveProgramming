#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
struct seg_tree{
    vector<T> seg;
    function<T(T,T)> func=plus<>();
    int n;
    seg_tree(int n){set_size(n);}
    seg_tree(){}
    void set_size(int n){this->n=n;seg.resize(n*2);}
    void set_func(function<T(T,T)> f){func=f;}
    void update(int a,T b){
        seg[a+=n]=b;
        for(a>>=1;a;a>>=1)seg[a]=func(seg[a*2],seg[a*2+1]);
    }
    int query(int a,int b){
        a+=n,b+=n;
        if(a==b)return seg[a];
        T l=seg[a++],r=seg[b--];
        for(;a<=b;a>>=1,b>>=1){
            if(a&1)l=func(l,seg[a]),a++;
            if(!(b&1))r=func(seg[b],r),b--;
        }
        return func(l,r);
    }
};
