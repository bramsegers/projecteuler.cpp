#include <iostream>
using LL = unsigned long long;

LL N=1000000;

int main(){
    int mlen=0, mnum=0;
    for(LL n=1;n<N;n++){
        LL len=1;
        LL num=n;
        while(num>1){
            num=(num&1)?3*num+1:num/2;
            len++;
        }
        if(len>=mlen){
            mlen=len;
            mnum=n;
        }
    }
    std::cout << mnum;
}