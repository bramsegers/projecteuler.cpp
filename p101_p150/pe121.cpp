#include <iostream>

int N=15;

int main(){
    long long win=0, fac=1;
    for(int i=2;i<=N+1;i++) fac*=i;
    for(int i=0;i<1<<N;i++){
        int j=i,p=1,b=0;
        for(int k=0;k<N;k++){
            p*=j&1?1:k+1;
            b+=j&1;
            j>>=1;
        }
        if(2*b>N) win+=p;
    }
    std::cout << "P(win)=" << win << "/" << fac << "\n";
    std::cout << "payout=" << fac/win << "\n";
}