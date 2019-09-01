#include "../util/primes.h"
#include <algorithm>
#include <iostream>

int N=100000;
int E=10000;

int main(){
    
    struct num{int n;int rad;};
    num * nums=new num[N+1];
    for(int n=0;n<=N;n++) 
        nums[n]={n,1};
    
    for(int p:Primes(N).vec)
        for(int q=p;q<=N;q+=p)
            nums[q].rad*=p;

    std::sort(nums,nums+N+1,[](num& a,num& b){
        return (a.rad!=b.rad)?a.rad<b.rad:a.n<b.n;
    });
    
    std::cout << nums[E].n;
}