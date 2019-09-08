#include "../util/primes.h"
#include <iostream>

long long N=150000000;

int main(){
    long long sum=10;
    auto P=Primes(N+100);
    int s[]={1,3,7,9,13,27};
    for(long long n=10;n<N;n+=2){
        if(n%3==0) continue;
        if(n%5!=0) continue;
        if((n+2)%7<5) continue;
        bool valid=true;
        for(int i=0;valid && i<1000000;i++){
            long long p=P.vec[i],q=n%p;
            for(int j=0;valid && j<6;j++)
                if((q*q+s[j])%p==0)
                    valid=false;
        }
        for(int i=0,j=1;valid && j<=27;j+=2){
            bool a=i<6 && s[i]==j;
            bool pr=P.get(n*n+j);
            if(a!=pr) valid=false;
            if(a) i++;
        }
        if(valid){
            std::cout << n << "\n";
            sum+=n;
        }
    }
    std::cout << "sum:" << sum;
}