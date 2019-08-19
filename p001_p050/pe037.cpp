#include <stdio.h>
#include "../util/primes.h"

bool truncatable(int n,int d){
    
    static auto primes=Primes(1000000);

    //right trunc
    for(int p2=n;p2>0;p2/=10)
        if(!primes.get(p2)) return false;         
    
    //left trunc
    while((d/=10)>1){
        int p2=n-((n/d)*d);
        if(!primes.get(p2)) return false;
    }

    return true;
}

int main(){
    int sum=0;
    for(int n=10,d=10,c=0;c<11;n++){
        if(n==d) d*=10;
        if(truncatable(n,d)){
            c++;
            sum+=n;
            printf("%d: %d\n",c,n);
        }
    }
    printf("%d\n",sum);
}