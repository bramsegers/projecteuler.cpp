#include <stdio.h>

int main(){

    int sum=0, fac[10]={1};
    for(int i=1;i<10;i++)
        fac[i]=i*fac[i-1];

    for(int s,j,i=10;i<=1000000;i++){
        for(s=0,j=i;j>0;j/=10)
            s+=fac[j%10];
        if(i==s) sum+=s;
    }
    
    printf("%d\n",sum);
}