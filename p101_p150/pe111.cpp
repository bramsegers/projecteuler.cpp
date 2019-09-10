#include "../util/primes.h"
#include <math.h>
#include <iostream>
using LL=long long;

int D=10;
auto primes=Primes(pow(10,0.5*D)+1);

void gen_nums(LL& N,LL& S,LL n,int i,int d,int r){
    if(n==0 && i>0) return;
    if(i==D && r==0 && primes.get(n)) {N++;S+=n;}
    if(i==D) return;
    gen_nums(N,S,10*n+d,i+1,d,r);
    if(r>0) for(int j=0;j<10;j++)
        if(j!=d) gen_nums(N,S,10*n+j,i+1,d,r-1);
}

int main(){
    printf("%s %5s %5s %16s\n","d","M","N","S");
    LL sum=0;
    for(int d=0;d<10;d++){
        for(int r=1;;r++){
            LL N=0,S=0;
            gen_nums(N,S,0,0,d,r);
            if(N>0){
                printf("%d %5d %5lld %16lld\n",d,D-r,N,S);
                sum+=S;
                break;
            }
        }
    }
    printf("sum:%lld\n",sum);
}