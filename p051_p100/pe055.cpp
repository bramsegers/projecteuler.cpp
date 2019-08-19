#include <stdio.h>
#include "../util/infint.h"

int N=10000;

InfInt reverse(InfInt n){
    InfInt r=0;
    for(int i=0;i<n.numberOfDigits();i++)
        r=(r*10)+n.digitAt(i);
    return r;
}

bool isLychrel(int n){
    auto n1=InfInt(n);
    auto n2=reverse(n1);
    for(int i=0;i<50;i++){
        n1+=n2;
        n2=reverse(n1);
        if(n1==n2) return 0;
    }
    return 1;
}

int main(){
    int c=0;
    for(int i=1;i<N;i++)
        c+=isLychrel(i);
    printf("%d\n",c);
}