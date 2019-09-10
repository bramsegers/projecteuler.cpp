#include<map>
#include <iostream>
using LL=long long;

int N=20;
std::map<LL,LL> W;

LL ways(LL i,LL a,LL b){
    if(i==N) return 1;
    LL w=0, key=i*100+a*10+b;
    if(W.count(key)) return W[key];
    for(LL j=(i==0);a+b+j<10;j++)
        w+=ways(i+1,b,j);
    return W[key]=w;
}

int main(){
    std::cout << ways(0,0,0);
}