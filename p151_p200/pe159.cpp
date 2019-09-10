#include <algorithm>
#include <iostream>
using LL=long long;

int N=1000000;

int main(){
    int* D=new int[N];
    for(int i=2;i<N;i++)
        D[i]=(i-1)%9+1;
   
    for(int j=2;j<N;j++)
        for(int k=2;k<=j&&j*k<N;k++)
            D[j*k]=std::max(D[j*k],D[j]+D[k]);

    int sum=0;
    for(int i=2;i<N;i++) sum+=D[i];
    printf("P(%d)=%d",N,sum);
}