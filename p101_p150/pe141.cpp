#include "../util/gcd.h"
#include <math.h>
#include <iostream>
using LL=long long;

LL N=1e12;

int main(){
    LL sum=0;
    for(LL a=2;a*a*a<N;a++)
        for(LL b=1;b<a;b++){
            if(a*a*a*b+b*b>=N) break;
            if(gcd(a,b)>1) continue;
            for(LL c=1;;c++){
                LL n=a*a*a*b*c*c+c*b*b;
                if(n>=N) break;
                LL s=sqrt(n);
                if(s*s==n) sum+=n;
            }
        }
    std::cout << sum;
}