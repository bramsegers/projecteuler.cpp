#include <math.h>
#include <iostream>

bool pandigital(long n){
    int d,p=0;
    while(n>0){
        d=n%10;
        if((p>>d)&1) return 0;
        p|=1<<d;
        n/=10;
    }
    return p+2==1<<10;
}

int main(){
    double a=log10((1+sqrt(5))/2);
    double b=log10(sqrt(5));
    long f0=0,f1=1,f;
    for(long h,n=2;;n++){
        f=(f0+f1)%1000000000;
        f0=f1;
        f1=f;
        if(!pandigital(f)) continue;
        h=(long)pow(10,n*a-b-((long)(n*a-b))+8);
        if(!pandigital(h)) continue;
        std::cout << n;
        break;
    }
}