#include <iostream>

//int N=1000000000;
int N=100000000;

int reverse(int n){
    int r=0;
    for(;n;n/=10)
        r=r*10+n%10;
    return r;
}

bool odd(int n){
    for(;n;n/=10)
        if(((n%10)&1)==0)
            return 0;
    return 1;
}

int main(){
    int count=0;
    for(int m=0,n=0;n<N;n++)
        if(n==m) m+=10;
        else count+=odd(n+reverse(n));
    std::cout << count;
}