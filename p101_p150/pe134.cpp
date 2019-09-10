#include "../util/primes.h"
#include <iostream>
using LL=long long;

int N=1000000;

LL diophantine(LL a,LL b){
    LL x0=1,x=0;
    LL y0=0,y=1;
    LL t,q;
    while(b){
        q=a/b;
        t=a;
        a=b;
        b=t%b;
        t=x0;
        x0=x;
        x=t-q*x;
        t=y0;
        y0=y;
        y=t-q*y;
    }
    return y0;
}

int main(){
    LL sum=0;
    auto pr=Primes(N);
    while(!pr.get(++N)){};
    pr.vec.push_back(N);
    for(int i=2;i<pr.vec.size()-1;i++){
        LL x,d=1;
        LL p1=pr.vec[i];
        LL p2=pr.vec[i+1];
        while(d<p1) d*=10;
        x=(p1*diophantine(d,p2))%d;
        sum+=(x<0?x+d:x)*p2;
    }
    std::cout << sum;
}