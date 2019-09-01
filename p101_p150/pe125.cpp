#include <math.h>
#include <stdio.h>

int N=100000000;

bool consec_square(int n){
    int j=sqrt(n);
    int s=j*j, i=j;
    if(s==n) return 0;
    while(true){
        while(s<n && --i) s+=i*i;
        if(s==n) return 1;// | printf("%d=%d^2+...+%d^2\n",n,i,j);
        if(i==0) return 0;
        s-=j*j;
        j--;
    }
}

int main(){
    long long sum=0;
    for(int n=1;;n++){
        long long a,b,k=0,p=1;
        for(int m=n;m;m/=10,p*=10)
            k=10*k+m%10;
        a=p*n+k;
        b=p*(n/10)+k;
        if(b>=N) break;
        if(consec_square(a)) sum+=a;
        if(consec_square(b)) sum+=b;
    }
    printf("%lld\n",sum);
} 