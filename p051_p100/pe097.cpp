#include "../util/infint.h"

InfInt a=28433;
InfInt b=7830457;
InfInt mod=10000000000;

InfInt modPow(InfInt b,InfInt e,InfInt m){
    InfInt p;
    for(p=1;e>0;e/=2,b=(b*b)%m)
        if(e%2==1) p=(p*b)%m;
    return p;
}

int main(){
    InfInt ans=(a*modPow(2,b,mod)+1)%mod;
    std::cout << ans;
}