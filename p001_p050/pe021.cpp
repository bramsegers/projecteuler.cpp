#include <iostream>

int N=10000;

int main(){
    int sum=0;
    int* a=new int[N+1];
    for(int d=1;d<=N;d++)
        for(int i=2*d;i<=N;i+=d)
            a[i]+=d;
    for(int i=0;i<=N;i++){
        int j=a[i];
        if(i!=j && j<=N && a[j]==i){
            std::cout << i << " - " << j << "\n";
            sum+=i;
        }
    }
    std::cout << sum << "\n";
}