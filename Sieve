#include<bits/stdc++.h>
using namespace std;
bitset<1000000> p;
// if a number "i" is prime, then p[i] will be evaluated as true, otherwise it will be evaluated as false
int main(){
    int i,j;
    p.set();
    p[0]=0,p[1]=0;
    for(i=2;i*i<1000000;i++)if(p[i])for(j=i*i;j<1000000;j+=i)p[i]=0;
}
