#include <iostream>
using LL=long long;

LL N=1000000000000LL;

int main(){
    LL t0,t1=0,t=1;
    LL b0,b1=1,b=1;
    while(t<=N){
        t0=t1;
        t1=t;
        t=6*t-t0-2;
        b0=b1;
        b1=b;
        b=6*b-b0-2;
        std::cout << t << " " << b << "\n";
    }
    std::cout << b;
}