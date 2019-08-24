#include <set>
#include <math.h>
#include <stdio.h>
#include "../util/primes.h"

int N=50000000;

int main(){
    auto P=Primes(sqrt(N)).vec;
    std::set<int> s;
    for(int p:P){
        for(int q:P){
            if(p*p+q*q*q>N) break;
            for(int r:P){
                int n=p*p+q*q*q+r*r*r*r;
                if(n>N) break;
                s.insert(n);
            }
        }
    }    
    printf("%d\n",s.size());
}