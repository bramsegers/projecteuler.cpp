#include <stdio.h>
#include "../util/primes.h"

double R=0.10;

int main(){
    auto primes=Primes(100000);
    long long p=0,t=1,n=1,len=1;
    while(p==0||p>R*t){
        for(int i=0;i<4;i++){
            t++;
            n+=len+1;
            p+=primes.get(n);
        }
        len+=2;
    }
    printf("%d\n",len);
}