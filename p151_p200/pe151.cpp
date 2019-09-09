#include <iostream>

void f(double& E,double p,int a2,int a3,int a4,int a5){
    int sum=a2+a3+a4+a5;
    if(!sum) return;
    if(sum==1 && !a5) E+=p;
    if(a2) f(E,(p*a2)/sum,a2-1,a3+1,a4+1,a5+1);
    if(a3) f(E,(p*a3)/sum,a2,a3-1,a4+1,a5+1);
    if(a4) f(E,(p*a4)/sum,a2,a3,a4-1,a5+1);
    if(a5) f(E,(p*a5)/sum,a2,a3,a4,a5-1);
}

int main(){
    double E=0;
    f(E,1,1,1,1,1);
    std::cout << E;    
}