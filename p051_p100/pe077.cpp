#include <map>
#include <stdio.h>
#include "../util/primes.h"

int N=5000;
auto pr=Primes(N).vec;

int ways(int n,int i){
    if(n==0) return 1;
    int rv=0;
    for(int j=i;pr[j]<=n;j++)
        rv+=ways(n-pr[j],j);
    return rv;
}

int main(){
    for(int n=1;;n++){
        int w=ways(n,0);
        printf("n:%d ways:%d\n",n,w);
        if(w>N) break;
    }
}