#include <iostream>
#include "../util/primes.h"

int N=500;

int main(){
    int t;
    auto primes=Primes(10000);
    for(int divs=0,i=1;divs<N;i++){
        divs=1;
        t=i*(i+1)/2;
        for(auto f:primes.factors(t))
            divs*=f.exp+1;
    }
    std::cout << t;
}