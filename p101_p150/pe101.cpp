#include <iostream>
using LL=long long;

LL u(LL n){
    return 1
    -n
    +n*n
    -n*n*n
    +n*n*n*n
    -n*n*n*n*n
    +n*n*n*n*n*n
    -n*n*n*n*n*n*n
    +n*n*n*n*n*n*n*n
    -n*n*n*n*n*n*n*n*n
    +n*n*n*n*n*n*n*n*n*n;
}

LL L(int i,int j){
    LL rv=0;
    for(int k=1;k<=i;k++){
        LL n=u(k), d=1;
        for(LL m=1;m<=i;m++)
            if(k!=m){
                n=n*(j-m);
                d=d*(k-m);
            }
        rv+=n/d;
    }
    return rv;
}

int main(){
    LL sum=0;
    for(int j,i=0;i<=10;i++){
        for(j=0;j<=10 && L(i+1,j+1)==u(j+1);) j++;
        LL fit=(i==10)?0:L(i+1,j+1);
        std::cout<<"degree:"<<i<<" fit:"<<fit<<"\n";
        sum+=fit;
    }
    std::cout << sum;
}