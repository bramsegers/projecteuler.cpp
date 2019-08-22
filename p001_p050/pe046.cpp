#include <stdio.h>
#include <math.h>
#include "../util/primes.h"

bool goldbachIsRight(int i){
    static auto primes=Primes(1000000);
    if(primes.get(i)) return true;
    for(int p:primes.vec){
        int s=(i-p)/2;
        if(p==2||s<1) continue;
        int a=(int) sqrt(s);
        if(a*a==s){
            printf("%d = %d +2*%d^2\n",i,p,a);
            return true;
        }
    }
    return false;
}

int main(){
    int i=3;
    while(goldbachIsRight(i)) i+=2;
    printf("%d\n",i);
}