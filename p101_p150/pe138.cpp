#include <iostream>

int N=12;

int main(){
    long long n=1,m=0,s=0,t;
    for(int c=1;c<=N;c++){
        t=m;
        m=n;
        n=4*n+t;
        s+=n*n+m*m;
    }
    std::cout << s;
}