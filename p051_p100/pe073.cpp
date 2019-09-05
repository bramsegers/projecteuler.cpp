#include "../util/gcd.h"
#include <stdio.h>

int p1=1,q1=3;
int p2=1,q2=2;
int N=12000;

int main(){
    int count=0;
    for(int q=N;q>1;q--){
        int a=p1*q/q1+1;
        int b=(p2*q-1)/q2;
        if(a>b) continue;
        for(int p=a;p<=b;p++)
            count+=gcd(p,q)==1;
    }
    printf("%d\n",count);
}

