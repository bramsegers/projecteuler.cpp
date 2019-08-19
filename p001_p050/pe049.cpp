#include <stdio.h>
#include "../util/primes.h"

bool anagram(int p1,int p2){
    int a[10]={};
    int b[10]={};
    while(p1>0) {a[p1%10]++;p1/=10;}
    while(p2>0) {b[p2%10]++;p2/=10;}
    for(int i=0;i<10;i++)
        if(a[i]!=b[i]) return false;
    return true;
}

int main(){
    int P1,P2,P3,N=10000;
    auto primes=Primes(N);
    for(int p1:primes.pr){
        for(int i=2;i<(N-p1)/2;i+=2){
            int p2=p1+i;
            int p3=p2+i;
            if(!primes.get(p2)) continue;
            if(!primes.get(p3)) continue;
            if(!anagram(p1,p2)) continue;
            if(!anagram(p1,p3)) continue;
            printf("%d %d %d %d\n",i,p1,p2,p3);
            P1=p1;P2=p2;P3=p3;
        }
    }
    printf("ans=%d%d%d\n",P1,P2,P3);
}