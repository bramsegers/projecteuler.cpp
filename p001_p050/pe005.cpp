#include <iostream>
#include "../util/primes.h"

int N=20;

int main(){
    int ans=1;
    auto primes=Primes(N);
    for(int p:primes.pr)
        for(int q=p;q<=N;q*=p)
            ans*=p;
    std::cout << ans;
}