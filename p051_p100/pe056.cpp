#include <stdio.h>
#include "../util/infint.h"

int A=100;
int B=100;

int main(){
    int max=0;
    for(int a=1;a<A;a++){
        InfInt n=1,p=a;
        for(int b=1;b<B;b++){
            n*=p;
            int sum=0;
            for(int i=0;i<n.numberOfDigits();i++)
                sum+=n.digitAt(i);
            if(sum>max) max=sum;
        }
    }
    printf("%d\n",max);
}