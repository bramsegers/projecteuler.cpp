#include "../util/gcd.h"
#include <iostream>

//int N=100000;
int N=100000000;

int main(){
    long long sum=0;

    // rational integer divisors
    for(long long n=1;n<=N;n++)
        sum+=n*(N/n);

    // Gaussian integer divisors 
    for(long long a=1;a*a<=N;a++)
        for(long long b=1;b*b<=N;b++)
            if(gcd(a,b)==1){
                long long d=a*a+b*b,k=d,m;
                for(m=2;k<=N;k+=d,m+=2)
                    sum+=m*a*(N/k);
            }

    std::cout << sum;
}