#include <iostream>

int N=1000000;
int S=10;

int main(){
    int* a=new int[N];
    long long x,i,n;
    for(x=2;x<N;x++)
        for(i=x/4+1;i<x;i++){
            n=x*(4*i-x);
            if(n>=N) break;
            a[n]++;
        }
    int count=0;
    for(x=2;x<N;x++)
        if(a[x]==S) count++;
    std::cout << count;
}