#include <iostream>
#include "../util/infint.h"

int N=100;

InfInt fac(int n){
    InfInt f=1;
    for(int i=2;i<=n;i++)
        f*=i;
    return f;
}

int main(){
    int sum=0;
    auto a=fac(N);
    for(int i=0;i<a.numberOfDigits();i++)
        sum+=a.digitAt(i);
    std::cout << sum;
}