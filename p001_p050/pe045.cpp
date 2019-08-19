#include <stdio.h>
#include <math.h>

using LL = long long;

LL T,P,H;

bool isTri(LL i){
    double d=8*i+1;
    LL s=(LL)sqrt(d);
    T=(s-1)/2;
    return T*(T+1)/2==i;
}

bool isPen(LL i){
    double d=24*i+1;
    LL s=(LL)sqrt(d);
    P=(s+1)/6;
    return P*(3*P-1)/2==i;
}

bool isHex(LL i){
    double d=8*i+1;
    LL s=(LL)sqrt(d);
    H=(s+1)/4;
    return H*(2*H-1)==i;
}

int main(){
    for(LL i=1;;i++){
        LL n=2*i*i-i;
        if(isTri(n) && isPen(n) && isHex(n)){
            printf("T(%lld) = P(%lld) = H(%lld) = %lld\n",T,P,H,n);
            if(n>40755) return 0;
        }
    }   
}