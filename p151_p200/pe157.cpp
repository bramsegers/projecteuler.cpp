#include "../util/gcd.h"
#include <iostream>
using LL=long long;

int N=9;

int main(){
    LL count=0;
    for(LL n=1,t=10;n<=N;n++,t*=10){
        for(LL r=0;(1<<r)<=t;r++){
            for(LL s=1;;s*=5){
                LL a=(1<<r)*s;
                if(a>t) break;
                LL b=(a+t)*t;
                if(b%a) continue;
                LL g=gcd(a+t,b/a);
                for(LL i=1;i*i<=g;i++)
                    if(g%i==0) count+=2;
            }
        }
    }
    std::cout << count;
}