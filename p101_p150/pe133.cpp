#include "../util/primes.h"
#include "../util/modpow.h"
#include <iostream>

int N=100000;

int main(){
    long long n,p10,sum=0;
    for(long long p:Primes(N).vec)
        for(sum+=p,n=1,p10=1;n<=18;n++)
            if(modpow(10,p10*=10,9*p)==1){
                sum-=p;
                break;
            }
    std::cout << sum;
}