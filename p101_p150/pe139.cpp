#include "../util/gcd.h"
#include <iostream>

int N=100000000;

int main(){
    int count=0;
    for(int n,m=1;m*m<=N/2;m++){
        for(n=(m&1)+1;n<m;n+=2){
            int c=m*m+n*n;
            if(c>N/2) break;
            if(gcd(m,n)>1) continue;
            int a=m*m-n*n;
            int b=2*m*n;
            if(c%(b-a)==0)
                count+=N/(a+b+c);
        }
    }
    std::cout << count;
}