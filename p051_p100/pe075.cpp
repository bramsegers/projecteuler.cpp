#include "../util/gcd.h"
#include <stdio.h>
#include <map>

int N=1500000;

int main(){
    std::map<int,int> s;
    for(int c,n,m=1;m*m<=N/2;m++)
        for(n=(m&1)+1;n<m && (c=m*m+n*n)<=N/2;n+=2)
            if(gcd(m,n)==1){
                int a=m*m-n*n;
                int b=2*m*n;
                for(int p,k=1;(p=k*(a+b+c))<=N;k++){
                    if(!s[p]) s[p]=1;
                    else s[p]++;
                }
            }
    int count=0;
    for(auto e:s)
        count+=e.second==1;
    printf("%d\n",count);
}