#include <iostream>
using LL=long long;

int N=26;

int main(){

    auto choose=[](LL n,LL k){
        LL c=1;
        if(n-k<k) k=n-k;
        for(LL i=0;i<k;i++){
            c*=n-i;
            c/=i+1;
        }
        return c;
    };

    LL maxn=0,maxp=0;
    for(LL n=0;n<=N;n++){
        LL p=choose(N,n)*((1<<n)-n-1);
        printf("P(%lld)=%lld\n",n,p);
        if(p>maxp) {maxp=p;maxn=n;}
    }
    printf("Max found at P(%lld)=%lld\n",maxn,maxp);
}