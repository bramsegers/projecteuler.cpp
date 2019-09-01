#include "../util/primes.h"
#include <iostream>

long long N=1e10;

int main(){
    auto pr=Primes(1000000).vec;
    long long n=1,p=0,r=0;
    while(r<N){
        n+=2;
        p=pr[n-1];
        r=(2*p*n)%(p*p);
    }
    std::cout << n;
}