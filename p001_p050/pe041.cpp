#include <stdio.h>
#include "../util/primes.h"

bool pandigital(int p){
    int d=1,set=0;
    while(p>0){
        set|=1<<(p%10);
        p/=10;
        d++;
    }
    return set==(1<<d)-2;
}

int main(){
    auto pr=Primes(987654321).pr;
    int i=pr.size()-1;
    while(!pandigital(pr[i])) i--;
    printf("%d\n",pr[i]);
}