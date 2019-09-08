#include <set>
#include <iostream>

int N=30;

int main(){
    std::set<long long> set;
    int K[]={0,0,-3,-3,-4,-4,2,2};
    int B[]={-1,1,-2,2,-5,5,-7,7};
    for(int j=0;j<8;j++){
        long long t,k=K[j],b=B[j];
        for(int i=0;i<N;i++){
            t=k;
            k=-9*k-4*b-14;
            b=-20*t-9*b-28;
            if(k>0) set.insert(k);
        }
    }
    long long sum=0;
    for(auto s:set){
        sum+=s;
        if(--N==0) break;
    }
    std::cout << sum;
}