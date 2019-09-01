#include <iostream>
using LL=unsigned long long;

int N=4000000;

LL min,max;
LL primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};

void search(int n,int p,LL q,LL s){
    for(int i=0;i<n;i++) q*=primes[p];
    s*=n*2+1;
    if(q>=max) return;
    if(++p==14 && s/2+1>N && q<min) min=q;
    for(int j=0;p<14&&j<=n;j++) search(j,p,q,s);
}

int main(){
    max=1;
    for(int i=0;i<14;i++) max*=primes[i];
    min=max;
    for(int i=0;i<=54;i++)
        search(i,0,1,1);
    std::cout << min;
}