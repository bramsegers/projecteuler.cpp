#include <iostream>

int N=100;

long long choose(int n,int k){
    long long c=1;
    if(n-k<k) k=n-k;
    for(int i=1;i<=k;i++){
        c*=n-k+i;
        c/=i;
    }
    return c;
}

int main(){
    long long a=choose(N+10,10)+choose(N+9,9)-10*N-2;
    std::cout << a;
}