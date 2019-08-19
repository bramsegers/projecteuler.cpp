#include <iostream>

int N=1001;

int main(){
    long sum=1;
    for(long i=2;i<=(N+1)/2;i++)
        sum+=16*i*i-28*i+16;
    std::cout << sum;
}