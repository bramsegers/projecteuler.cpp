#include <iostream>
#include "../util/primes.h"

int N=1000000;

int main(){
    auto P=Primes(N);
    auto pr=P.pr;
    int pi=pr.size();
    int mlen=0,msum;
    for(int i=0;i<pi;i++){
        for(int sum=pr[i],j=i+1;j<pi;j++){
            sum+=pr[j];
            if(sum>N) break;
            if(j-i+1<=mlen) continue;
            if(!P.get(sum)) continue;
            mlen=j-i+1;
            msum=sum;
            std::cout << mlen << ' ' << pr[i] << ' ' << pr[j] << ' ' << msum << '\n';
        }
    }
    std::cout << msum;
}