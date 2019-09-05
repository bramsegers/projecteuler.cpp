#include "../util/primes.h"
#include "../util/modpow.h"
#include <iostream>

int N=40;
int K=1000000000;

int main(){
    long long sum=0,n=0;
    for(long long p:Primes(1000000).vec)
        if(modpow(10,K,9*p)==1){
            sum+=p;
            if(++n==N) break;
        }
    std::cout << sum;
}