#include <iostream>

int N=1000000;

void perm(long long n,int mask){
    if(mask+1==1<<10 && --N==0) 
        std::cout << n;
    for(int i=0;i<10;i++)
        if(((mask>>i)&1)==0)
            perm(10*n+i,mask|(1<<i));
}

int main(){
    perm(0,0);
}