#include <iostream>
#include "../util/infint.h"

int N=1000;

InfInt pow(int b,int e){
    InfInt f=1;
    for(int i=0;i<e;i++)
        f*=b;
    return f;
}

int main(){
    int sum=0;
    auto a=pow(2,N);
    for(int b=0;b<a.numberOfDigits();b++)
        sum+=a.digitAt(b);
    std::cout << sum;
}