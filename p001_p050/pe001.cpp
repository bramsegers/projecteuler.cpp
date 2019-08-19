#include <stdio.h>

int N=1000, p1=3, p2=5;

int sum(int n,int p){
    return p*(n/p)*(n/p+1)/2;
}

int main(){
    int ans=0;
    ans+=sum(N-1,p1);
    ans+=sum(N-1,p2);
    ans-=sum(N-1,p1*p2);
    printf("%d\n",ans);
}