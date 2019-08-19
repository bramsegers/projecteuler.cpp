#include <iostream>
#include <math.h>
#include "../util/primes.h"

int main(){
    long long N=600851475143;
    auto primes=Primes(sqrt(N));
    auto f=primes.factors(N);
    auto maxpr=f[f.size()-1].prime;
    std::cout << maxpr << std::endl;
}