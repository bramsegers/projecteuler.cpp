#include <iostream>

int N=12;

long choose(long n,long k){
    return (n<k)?0:(k==0||k==n)?1:choose(n-1,k-1)+choose(n-1,k);
}

long tests(long s,long n){
    return (choose(n,s)*choose(n-s,s)/2)-(choose(n,2*s)*choose(2*s,s)/(s+1));
}

int main(){
    long sum=0;
    for(int i=1;i<=N/2;i++)
        for(int j=i;j<=N-i;j++)
            sum+=(i==j)?tests(i,N):0;
    std::cout << sum;
}