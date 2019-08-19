#include <stdio.h>
#include "../util/primes.h"

int N=4;

int main(){
    auto primes=Primes(1000000);
    for(int f=0,s=0,n=2;;n++){
        int dpf=primes.factors(n).size();
        if(dpf!=N) s=0;
        else if(++s==1) f=n;
        if(s==N){
            printf("%d\n",f);
            return 0;
        }
    }
}

