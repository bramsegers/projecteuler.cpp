#include <set>
#include <iostream>

//int K=12;
int K=12000;
int * mem=new int[K+1];

void search(int i,int sum,int prod,int next){
    if(i==100){
        int k=100+prod-sum;
        if (k<=K && prod<mem[k]) mem[k]=prod;
        return;
    }
    for(int n=next;2*n<=K && prod*n<=K*2;n++)
        search(i+1,sum+n,prod*n,n);
}

int main(){
    for(int i=0;i<=K;i++)
        mem[i]=2*i;
    search(0,0,1,1);
    std::set<int> s;
    for(int i=2;i<=K;i++)
        s.insert(mem[i]);
    int sum=0;
    for(int n:s) sum+=n;
    std::cout << sum;
}