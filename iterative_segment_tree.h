#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
struct seg_tree{
    vector<T> seg;
    int size;
    // Merging two segments
    static T merge(T a,T b){
        return min(a,b);
    }
    // Initialize Segment Tree.
    seg_tree(int size,T init_value=0){
        seg.resize(size*2,init_value);
        for(int i=size-1;i;i--)seg[i]=merge(seg[i*2],seg[i*2+1]);
    }
    void update(int pos,T val){
        seg[pos+=size]=val;
        for(pos>>=1;pos;pos>>=1)seg[pos]=merge(seg[pos*2],seg[pos*2+1]);
    }
    T query(int l,int r){
        l+=size,r+=size;
        if(l==r)return seg[l];
        T lval=seg[l++],rval=seg[r--];
        for(;l<=r;l>>=1,r>>=1){
            if(l&1)lval=merge(lval,seg[l++]);
            if(!(r&1))rval=merge(seg[r--],rval);
        }
        return merge(lval,rval);
    }
};
