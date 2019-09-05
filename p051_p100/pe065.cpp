#include <iostream>
#include "../util/infint.h"

int N=100;

int main(){

    int* e=new int[N]{2,1};
    for(int i=1,j=2;j<N;i++){
        e[j++]=2*i;
        e[j++]=1;
        e[j++]=1;
    }

    InfInt p,q,p1=1,q1=1,p2=0,q2=0;
    for(int i=0;i<N;i++){
        p=p1*e[i]+p2;
        q=q1*e[i]+q2;
        p2=p1;
        q2=q1;
        p1=p;
        q1=q;
        std::cout << "p/q=" << p << "/" << q << "\n"; 
    }

    int sum=0;
    for(int i=0;i<p1.numberOfDigits();i++)
        sum+=p1.digitAt(i);
    std::cout << sum;
}