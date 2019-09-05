#include <stdio.h>
#include "../util/infint.h"

int N=100;
int max=1000000;

int main(){
    
    int count=0;
    InfInt* f=new InfInt[N+1]{1};

    for(int i=1;i<=N;i++)
        f[i]=InfInt(i)*f[i-1];
    
    for(int n=1;n<=N;n++)
        for(int r=0;r<=n;r++)
            if(f[n]/(f[r]*f[n-r])>max)
                count++;
    
    printf("%d\n",count);
}