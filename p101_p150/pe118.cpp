#include "../util/primes.h"
#include <iostream>

auto p=Primes(100000);

int ways(int n,int prev){
    if(n==0) return 1;
    int rv=0,q=0;
    while(n>0){
        q=10*q+n%10;
        n/=10;
        if(q>prev && p.get(q))
            rv+=ways(n,q);
    }
    return rv;
}

int perm(int n,int mask){
    if(mask==(1<<10)-2)
        return ways(n,0);
    int rv=0;
    for(int i=1;i<10;i++)
        if(((mask>>i)&1)==0)
            rv+=perm(10*n+i,mask|(1<<i));
    return rv;
}

int main(){
    std::cout << perm(0,0);
}