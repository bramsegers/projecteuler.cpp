#include <stdio.h>

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int removeFirst(int n,int r){
    int rv=0,m=1,f=0,d;
    while(n>0){
        d=n%10;
        n/=10;
        if(d==r && f==0)
            f++;
        else{
            rv+=m*d;
            m*=10;
        }
    }
    return rv;
}

int main(){
    int N=1,D=1;
    for(int n=10;n<100;n++){
        for(int d=n+1;d<100;d++){
            for(int i=1;i<10;i++){
                int n2=removeFirst(n,i);
                int d2=removeFirst(d,i);
                if(n!=n2 && d!=d2 && n*d2==n2*d){
                    printf("%d/%d = %d/%d\n",n,d,n2,d2);
                    N*=n;
                    D*=d;
                }
            }
        }
    }
    int g=gcd(N,D);
    printf("%d/%d = %d/%d\n",N,D,N/g,D/g);
}