#include <iostream>
#include "../util/primes.h"
using namespace std;

int N=8;

int replace(int n,int i,int j){
    int r=0,m=1,d;
    while(n>0){
        d=n%10;
        if(d==i) d=j;
        r+=m*d;
        m*=10;
        n/=10;
    }
    return d==0?-1:r;
}

int main(){
    auto primes=Primes(1000000);
    for(int p:primes.pr){
        int c=p;
        int dig=0;
        while(c>0){
            int d=c%10;
            c/=10;
            dig|=1<<d;
        }
        for(int k=0;dig>0;k++,dig/=2){
            if(!(dig&1)) continue;
            int count=0;
            string out="";
            for(int i=0;i<10;i++){
                int fam=replace(p,k,i);
                if(fam>0 && primes.get(fam)){
                    count++;
                    out+=to_string(fam)+" ";
                }
            }
            if(count>=N){
                cout << out << "\n";
                return 0;
            }
        }
    }
    cout << "Not found in prime range\n";
    return -1;
}