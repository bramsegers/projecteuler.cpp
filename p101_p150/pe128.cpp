#include "../util/primes.h"
#include <iostream>

int N=2000;

int main(){
    auto pr=Primes(1000000);
    long long n,c=1,t=0;
    for(n=1;c<N;n++){
        if(pr.get(6*n-1) && pr.get(6*n+1) && pr.get(12*n+5)){
            c++;
            t=3*n*n-3*n+2;
        }
        if(n==1 || c==N) continue;
        if(pr.get(6*n+5) && pr.get(6*n-1) && pr.get(12*n-7)){
            c++;
            t=3*n*n+3*n+1;
        }
    }
    std::cout << t;
}