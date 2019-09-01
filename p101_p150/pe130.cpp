#include "../util/primes.h"
#include <iostream>

int N=25;

int main(){
    int sum=0;
    auto primes=Primes(1000000);
    for(int c,m,f=0,n=3;f<N;n+=2){
        if(n%5==0) continue;
        if(primes.get(n)) continue;
        for(c=1,m=1;m!=0;c++)
            m=(m*10+1)%n;
        if((n-1)%c) continue;
        f++;
        sum+=n;
    }
    std::cout << sum;
}