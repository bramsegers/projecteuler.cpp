#include <math.h>
#include <stdio.h>
using LL = long long;

LL N=1000000000;

int main(){
    LL sum=0;
    LL m=(N+2)/6;
    LL M=3*m*m+4*m+1;
    LL t,k0=1,k=4;
    while(k*k<M){
        LL d=sqrt(3*k*k+1);
        if(d%3==1){
            LL n=((d+2)/3)*2;
            sum+=3*n-2;
            printf("(%lld,%lld,%lld)\n",n,n-1,n-1);
        }
        if(d%3==2){
            LL n=((d-2)/3)*2;
            sum+=3*n+2;
            printf("(%lld,%lld,%lld)\n",n,n+1,n+1);
        }
        t=k0;
        k0=k;
        k=4*k-t;
    }
    printf("%lld\n",sum);
}