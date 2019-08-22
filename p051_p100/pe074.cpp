#include <iostream>
#include <map>

int N=1000000;
int L=60;

int fac[10];
std::map<int,int> len;

int fac_sum(int n){
    int s;
    for(s=0;n>0;n/=10)
        s+=fac[n%10];
    return s;
}

int chain_len(int n){
    if(!len[n]){
        int s=fac_sum(n);
        if(s==n) len[n]=1;
        else len[n]=1+chain_len(s);
    }
    return len[n];
}

int main(){
    len[169]=3;
    len[871]=2;
    len[872]=2;
    fac[0]=1;
    for(int i=1;i<10;i++)
        fac[i]=i*fac[i-1];

    int count=0;
    for(int n=1;n<N;n++)
        count+=chain_len(n)==L;
    std::cout << count;
}