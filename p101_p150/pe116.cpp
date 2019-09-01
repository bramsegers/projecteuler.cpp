#include <map>
#include <iostream>

int N=50;
int L[]={2,3,4};
std::map<int,long long> m;

long long ways(int i,int n,int len){
    if(m.count(i)) return m[i];
    long long c=1;
    for(int j=i;j+len<=n;j++)
        c+=ways(j+len,n,len);
    return m[i]=c;
}

int main(){
    long long c=0;
    for(int len:L){
        c+=ways(0,N,len)-1;
        m.clear();
    }
    std::cout << c;
}