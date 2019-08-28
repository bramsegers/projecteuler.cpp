#include <iostream>

int S=1000;

int main(){
    long long n=0;
    int s=0,f=2*3*5*7;
    while(s<S){
        s=2;
        n+=f;
        for(int i=2;i<n;i++)
            s+=(n*n)%i==0;
    }
    std::cout << n;
}