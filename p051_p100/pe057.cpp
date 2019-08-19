#include <stdio.h>
#include "../util/infint.h"

int N=1000;

int main(){
    int count=0;
    InfInt p=1,q=1,t;
    for(int i=0;i<N;i++){
        t=p;
        p+=q+q;
        q+=t;
        count+=p.numberOfDigits()>q.numberOfDigits();
    }
    printf("%d\n",count);
}