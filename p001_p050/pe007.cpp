#include <iostream>
#include "../util/primes.h"

int N=10001;

int main(){
    for(int i=N;;i*=2){
        auto primes=Primes(i);
        if(primes.vec.size()>=N){
            long long ans=primes.vec[N-1];
            std::cout << ans;
            break;
        }
    }
}