#include <map>
#include <stdio.h>
#include "../util/primes.h"

int N=5000;
auto primes=Primes(N).vec;

int ways(int a,int b,std::map<int,int> &m){
    int i=N*a+b;
    if(b<0) return 0;
    if(b==0) return m[i]=1;
    if(!m[i]){
        for(int p:primes){
            if(p>a) break;
            m[i]+=ways(p,b-p,m);
        }
    }
    return m[i];
}

int main(){
    for(int n=0;;n++){
        std::map<int,int> m;
        int w=0;
        for(int p:primes){
            if(p>=n) break;
            w+=ways(p,n-p,m);
        }
        printf("n:%d ways:%d\n",n,w);
        if(w>N) break;
    }
}