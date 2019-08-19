#include <stdio.h>
#include <math.h>

int main(){
    int sum=0;
    for(int s,j,i=2;i<1000000;i++){
        for(s=0,j=i;j>0;j/=10)
            s+=pow(j%10,5);
        if(i==s){
            printf("%d\n",i);
            sum+=s;
        }
    }
    printf("sum=%d\n",sum);
}