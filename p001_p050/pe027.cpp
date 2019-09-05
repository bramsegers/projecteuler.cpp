#include "../util/primes.h"
#include <iostream>

int A=1000;
int B=1000;

int main(){
    auto primes=Primes(1000000);
    int max=0, maxab=0;
    for(int a=-A+1;a<A;a++)
        for(int b=-B;b<=B;b++){
            int n=0;
            while(primes.get(n*n+a*n+b)) n++;
            if(n>=max){
                max=n;
                maxab=a*b;
            }
        }
    std::cout << maxab;
}