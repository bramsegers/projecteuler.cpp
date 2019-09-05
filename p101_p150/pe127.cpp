#include "../util/primes.h"
#include "../util/gcd.h"
#include <algorithm>
#include <iostream>

int C=120000;

int main(){

    struct rad{int n;int r;};
    rad* rads=new rad[C];
    int* rad2=new int[C];
    for(int n=0;n<C;n++)
        rads[n]={n,r:1};

    for(int p:Primes(C).vec)
        for(int q=p;q<C;q+=p)
            rads[q].r*=p;

    for(int n=0;n<C;n++)
        rad2[n]=rads[n].r;

    std::sort(rads,rads+C,[](rad& a,rad& b){
        return (a.r!=b.r)?a.r<b.r:a.n<b.n;
    });

    int sum=0;
    for(int c=1;c<C;c++)
        for(int i=0;rads[i].r*rad2[c]<c;i++){
            int b=rads[i].n;
            int a=c-b;
            if(b<c && a<b && 1LL*rad2[a]*rads[i].r*rad2[c]<c && gcd(a,b)==1)
                sum+=c;
        }
    std::cout << sum;
}