int tot[10000001];
int main(){
    int i,j;
    for(i=2;i<=10000000;i++)tot[i]=i;//init
    for(i=2;i<=10000000;i++)if(tot[i]==i)for(j=i;j<=1000000;j+=i)tot[j]=tot[j]/i*(i-1);//sketch seive (look up euler totient function)
    //tot[i] is the euler totient function evaluated at i, which is the number of positive integers less than i that are coprime to i
    //Complexity: O(NloglogN)
}