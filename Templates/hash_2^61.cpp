const unsigned long long p = (1LL << 61) - 1;
inline uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & p) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & p) + (ret >> 61);
    ret = (ret & p) + (ret >> 61);
    return ret - 1;
}
inline uint64_t add(uint64_t a,uint64_t b){
    uint64_t c=a+b;
    return c>=p?c-p:c;
}
inline uint64_t sub(uint64_t a,uint64_t b){
    return a>=b?a-b:a-b+p;
}
inline uint64_t po(uint64_t a,uint64_t b=p-2){
    uint64_t ans=1;
    for(;b;b>>=1,a=mul(a,a))if(b&1)ans=mul(ans,a);
    return ans;
}
