#include <stdio.h>
#include <math.h>

using LL = long long;

LL N=40755;

bool tri(LL i, LL& T){
    double d=8*i+1;
    LL s=(LL)sqrt(d);
    T=(s-1)/2;
    return T*(T+1)/2==i;
}

bool pen(LL i, LL& P){
    double d=24*i+1;
    LL s=(LL)sqrt(d);
    P=(s+1)/6;
    return P*(3*P-1)/2==i;
}

bool hex(LL i, LL& H){
    double d=8*i+1;
    LL s=(LL)sqrt(d);
    H=(s+1)/4;
    return H*(2*H-1)==i;
}

int main(){
    for(LL T,P,H,i=1;;i++){
        LL n=2*i*i-i;
        if(tri(n,T) && pen(n,P) && hex(n,H)){
            printf("T(%lld) = P(%lld) = H(%lld) = %lld\n",T,P,H,n);
            if(n>N) return 0;
        }
    }   
}