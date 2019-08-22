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
    auto p=Primes(987654321).vec;
    int i=p.size()-1;
    while(!pandigital(p[i])) i--;
    printf("%d\n",p[i]);
}