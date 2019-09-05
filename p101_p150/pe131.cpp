#include "../util/primes.h"
#include <iostream>

int N=1000000;

int main(){
    int c=0;
    auto primes=Primes(N);    
    for(long long p,i=0;;i++){
        p=(i+1)*(i+1)*(i+1)-i*i*i;
        if(p>=N) break;
        if(primes.get(p)) c++;
    }
    std::cout << c;
}