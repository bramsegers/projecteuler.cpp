#include "../util/gcd.h"
#include <stdio.h>

int N=1000;

int main(){
    int s[3*N]={};
    int M=N/2,maxs=0,maxp=0;
    for(int c,n,m=1;m*m<=M;m++)
        for(n=(m&1)+1;n<m && (c=m*m+n*n)<=M;n+=2)
            if(gcd(m,n)==1){
                int a=m*m-n*n;
                int b=2*m*n;
                for(int k=1;k*c<=M;k++){
                    int p=k*(a+b+c);
                    if(++s[p]>maxs){
                        maxs=s[p];
                        maxp=p;
                    }
                }
            }
    printf("(p,s)=(%d,%d)\n",maxp,maxs);
}