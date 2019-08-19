#include <iostream>
using LL = long long;

LL N=1000;
LL M=10000000000LL;

int main(){
    LL i,j,p,sum=0;
    for(i=1;i<=N;i++){
        for(p=i,j=1;j<i;j++)
            p=(p*i)%M;
        sum=(sum+p)%M;
    }
    std::cout << sum;
}