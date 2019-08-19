#include <iostream>

int main(){

    int n=28123;
    int a[n+1]={};
    int b[n+1]={};
    int c[n+1]={};

    for(int d=1;d<=n;d++)
        for(int i=2*d;i<=n;i+=d)
            a[i]+=d;

    int k=0;
    for(int i=2;i<=n;i++)
        if(a[i]>i) b[k++]=i;
    
    for(int i=0;i<k;i++)
        for(int j=0;j<k && b[i]+b[j]<n;j++)
            c[b[i]+b[j]]=1;

    int sum=0;
    for(int i=0;i<n;i++)
        sum+=c[i]?0:i;
    std::cout << sum;
}