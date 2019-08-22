#include <stdio.h>
#include "../util/primes.h"

int N=1000000;

bool circular(int n,int d,int r){
    static auto primes=Primes(N);
    for(int i=0;i<=r;i++){
        n=(n/10)+(d*(n%10));
        if(!primes.get(n)) return false;
    }
    return true;
}

int main(){
    int count=0;
    for(int r=0,d=1,n=2;n<N;n++){
        if(n==10*d) {d*=10;r++;}
        if(circular(n,d,r))
            printf("%d %d\n",++count,n);
    }
}