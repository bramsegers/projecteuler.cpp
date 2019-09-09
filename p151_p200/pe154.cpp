#include <iostream>

int N=200000;

int main(){

    auto factors=[](int f,int n){
        int r=0,t=1;
        while((t*=f)<=n)
            r+=n/t;
        return r;
    };

    int* f2=new int[N+1];
    int* f5=new int[N+1];
    for(int i=0;i<=N;i++){
        f2[i]=factors(2,i);
        f5[i]=factors(5,i);
    }

    int count=0;
    for(int i=0;i<=N;i++){
        for(int j=i;2*j<=N-i;j++){
            int k=N-i-j;
            int fac2=f2[N]-f2[i]-f2[j]-f2[k];
            int fac5=f5[N]-f5[i]-f5[j]-f5[k];
            count+= fac2<12 || fac5<12 ? 0
                    :i==k ? 1
                    :i==j || j==k ? 3
                    :6;
        }
    }
    std::cout << count;
}