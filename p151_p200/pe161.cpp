#include<map>
#include <iostream>
using LL=long long;

//int C=2,R=9;
int C=9,R=12;

std::map<LL,LL> W;

int bitset(LL n,LL i){return (n>>i)&1;}
int setbit(LL n,LL i){return n|(1<<i);}

LL state(int* a,LL c,LL s){
    for(int i=0;i<4;i+=2){
        int x=c+a[i];
        int y=a[i+1];
        if(x<0||x>=C) return -1;
        if(bitset(s,C*y+x)) return -1;
        s=setbit(s,C*y+x);
    }
    return s;
}

LL ways(LL c,LL r,LL s){
    if(s<0) return 0;
    if(c==C) {c=0;r++;s>>=C;}
    if(r==R) return s==0?1:0;
    if(bitset(s,c)) return ways(c+1,r,s);
    LL w=0,key=s*10000+c*100+r;
    if(W.count(key)) return W[key];
    static int a[6][4]={
        {0,1,1,1},{0,1,-1,1},{0,1,1,0},
        {1,0,1,1},{0,1,0,2},{1,0,2,0}
    };
    for(int i=0;i<6;i++)  
        w+=ways(c+1,r,state(a[i],c,s));
    return W[key]=w;
}

int main(){
    printf("P(%d,%d)=%lld",C,R,ways(0,0,0));
}