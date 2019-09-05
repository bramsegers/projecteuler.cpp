#include <iostream>
using LL = long long;

int N=15;

int main(){
    LL* fib=new LL[2*N+2]{0,1};
    for(int i=2;i<2*N+2;i++)
        fib[i]=fib[i-1]+fib[i-2];

    for(int i=1;i<=N;i++){
        LL n=fib[2*i]*fib[2*i+1];
        std::cout << i << " " << n << "\n";
    }
}