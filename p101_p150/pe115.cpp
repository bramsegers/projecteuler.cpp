#include <map>
#include <iostream>

int M=50;
int F=1000000;
std::map<int,long long> m;

long long ways(int i,int n){
    if(m.count(i)) return m[i];
    long long c=1;
    for(int j=i;j<n;j++)
        for(int k=j+M-1;k<n;k++)
            c+=ways(k+2,n);
    return m[i]=c;
}

int main(){
    for(int f=0,n=0;f<=F;n++){
        m.clear();
        f=ways(0,n);
        std::cout << n << " " << f << "\n";
    }
}