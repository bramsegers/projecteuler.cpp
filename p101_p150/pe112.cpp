#include <iostream>

double R=0.99;

bool bouncy(long n){
    bool asc =0;
    bool desc=0;
    int m,d=n%10;
    n/=10;
    while(n>0){
        m=n%10;
        asc |=d<m;
        desc|=d>m;
        if(asc && desc)
            return 1;
        n/=10;
        d=m;
    }
    return 0;
}

int main(){
    long b=0,n=1;
    while(b<R*n)
        b+=bouncy(++n);
    std::cout << n;
}