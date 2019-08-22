#include <stdio.h>
#include "../util/primes.h"

int N=1000000;

int main(){
    auto primes=Primes(N);
    auto p=primes.vec;
    int pi=p.size();
    int mlen=0,msum;
    for(int i=0;i<pi;i++){
        for(int sum=p[i],j=i+1;j<pi;j++){
            sum+=p[j];
            if(sum>N) break;
            if(j-i+1<=mlen) continue;
            if(!primes.get(sum)) continue;
            mlen=j-i+1;
            msum=sum;
            printf("%d %lld %lld %d\n",mlen,p[i],p[j],msum);
        }
    }
    printf("%d\n",msum);
}