#include<map>
#include <iostream>
using LL=long long;

int N=16;
std::map<LL,LL> W;

LL ways(LL i,LL a,LL b,LL c){
    if(i>N) return 0;
    LL key=(i<<3)+(a<<2)+(b<<1)+c;
    if(W.count(key)) return W[key];
    LL w=a*b*c?1:0;
    if(i) w+=ways(i+1,1,b,c);
    w+=ways(i+1,a,1,c);
    w+=ways(i+1,a,b,1);

    w+=ways(i+1,a,b,c)*13;
    return W[key]=w;
}

int main(){
    LL w=ways(0,0,0,0);
    std::cout << std::hex << w;
}