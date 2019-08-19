#include <math.h>
#include <stdio.h>

long gcd(long a,long b){
    return b==0?a:gcd(b,a%b);
}

int N=10000;

int main(){
    int count=0;
    for(long i=1;i<=N;i++){
        long z=(long)sqrt(i);
        long k=1, num=i-z*z, den=z;
        if(z*z==i) continue;
        for(long tmp,g,j,zn=1;;k++){
            j=zn*(z+den)/num;
            if(2*z==j) break;
            den=den-j*num;
            tmp=den;
            den=num;
            num=tmp;
            zn=den;
            den=-num;
            num=i-num*num;
            g=gcd(zn,num);
            zn/=g;
            num/=g;
        }
        count+=k&1;
    }
    printf("%d\n",count);
}