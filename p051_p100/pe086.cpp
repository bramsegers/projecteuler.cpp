#include <stdio.h>
#include <math.h>

int N=1000000;

int main(){
    int n,sum=0;
    for(n=1;sum<N;n++){  
        for(int i=1;i<2*n;i++){
            int p=i*i+n*n;
            int s=sqrt(p);
            if(s*s!=p) continue;
            sum+=i<n?i/2:i/2-i+n+1;
        }    
    }
    printf("%d %d\n",n-1,sum);
}