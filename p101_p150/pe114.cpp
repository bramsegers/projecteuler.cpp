#include <map>
#include <iostream>

int N=50;
std::map<int,long long> m;

long long ways(int i){
    if(m.count(i)) return m[i];
    long long c=1;
    for(int j=i;j<N;j++)
        for(int k=j+2;k<N;k++)
            c+=ways(k+2);
    return m[i]=c;
}

int main(){
    std::cout << ways(0);
}