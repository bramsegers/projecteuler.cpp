#include <iostream>
#include "../util/primes.h"

int N=2000000;

int main(){
    long long sum=0;
    auto primes=Primes(N-1);
    for(int p:primes.pr) sum+=p;
    std::cout << sum;
}