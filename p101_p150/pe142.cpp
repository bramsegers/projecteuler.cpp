#include <math.h>
#include <iostream>
using LL=long long;

int main(){

    auto square=[](LL n){
        LL r=sqrt(n);
        return r*r==n;
    };

    for(LL i=4;;i++){
        for(LL j=3;j<i;j++){
            LL a=i*i;
            LL c=j*j;
            LL f=a-c;
            if(f<=0) continue;
            if(!square(f)) continue;
            for(LL k=2-(j&1);k<j;k+=2){
                LL d=k*k;
                LL e=a-d;
                LL b=c-e;
                if(b<=0) continue;
                if(e<=0) continue;
                if(!square(b)) continue;
                if(!square(e)) continue;
                LL x=(d+c)/2;
                LL y=(e+f)/2;
                LL z=(c-d)/2;
                LL sum=x+y+z;
                printf("(x,y,z)=%lld %lld %lld\n",x,y,z);
                printf("sum=%lld\n",sum);
                return 0;
            }
        }
    }

}