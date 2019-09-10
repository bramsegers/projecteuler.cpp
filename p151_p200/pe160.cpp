#include "../util/primes.h"
#include <iostream>
using LL=long long;

int N=2560000;

LL modpow(LL b,LL e, LL m){
    LL p;
    for(p=1;e>0;e/=2,b=(b*b)%m)
        if(e%2==1) p=(p*b)%m;
    return p;
}

int fac(int p,int n){
    return n<p?0:(n/p)+fac(p,n/p);
}

int main(){
    LL f2,f5,m=1,M=100000;
    auto P=Primes(N);
    for(auto p:P.vec){
        int f=fac(p,N);
        if(p==2) f2=f;
        else if(p==5) f5=f;
        else m=(m*modpow(p,f,M))%M;
    }
    m=(m*modpow(2,f2-f5,M))%M;
    std::cout << m;
}