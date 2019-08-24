#include <math.h>
#include <stdio.h>
#include "../util/infint.h"

int N=100;
int D=100;

InfInt pow(int b,int e){
    InfInt p=1;
    for(int i=0;i<e;i++) p*=b;
    return p;
}

InfInt intSqrt(InfInt n){ // better algo than infint.h
    int d=n.numberOfDigits();
    InfInt t,x1=-1,x0=(d&1)
        ?pow(10,(d-1)/2)*2
        :pow(10,(d-2)/2)*7;
    while(x0!=x1){
        t=x0;
        x0=(x0+((n+x0-1)/x0))/2;
        x1=t;
    }
    return x0;
}

int main(){
    int sum=0;
    InfInt p=pow(10,2*D+10);
    for(int n=2;n<=N;n++){
        int s=sqrt(n);
        if(s*s==n) continue;
        InfInt t=intSqrt(p*n);
        int len=t.numberOfDigits();
        for(int j=len-1;j>len-1-D;j--)
            sum+=t.digitAt(j);
    }
    printf("%d\n",sum);
}