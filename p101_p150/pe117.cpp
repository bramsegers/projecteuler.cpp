#include <map>
#include <iostream>

int N=50;
int L[]={2,3,4};
std::map<int,long long> m;

long long ways(int i){
    if(m.count(i)) return m[i];
    long long c=1;
    for(int k:L)
        for(int j=i;j+k<=N;j++)
            c+=ways(j+k);
    return m[i]=c;
}

int main(){
    std::cout << ways(0);
}