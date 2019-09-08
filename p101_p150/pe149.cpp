#include <iostream>

int N=2000;

int maxSubArray(int* a, int len){
    int maxSoFar=a[0];
    int maxEndingHere=a[0];
    for(int i=1;i<len;i++){
        if(maxEndingHere<0)
            maxEndingHere=a[i];
        else maxEndingHere+=a[i];
        if(maxEndingHere>=maxSoFar)
            maxSoFar=maxEndingHere;
    }
    return maxSoFar;
}

int main(){

    int max=0;
    int* a=new int[N];
    int* s=new int[N*N+1];

    // generate sequence
    for(long long k=1;k<=N*N;k++){
        s[k]=k<56
            ?(100003-200003*k+300007*k*k*k)%1000000-500000
            :(s[k-24]+s[k-55]+1000000)%1000000-500000;
    }

    // horizontal
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++) a[i]=s[N*j+i+1];
        int sum=maxSubArray(a,N);
        if(sum>max) max=sum;
    }

    // vertical
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) a[j]=s[N*j+i+1];
        int sum=maxSubArray(a,N);
        if(sum>max) max=sum;
    }

    // diagonal
    for(int i=0;i<2*N-1;i++){
        int x=i<N-1?0:i-N+1;
        int y=i<N?i:N-1;
        int r=i<N?i+1:2*N-2-i+1;
        for(int j=0;j<r;j++) a[j]=s[N*(y--)+(x++)+1];
        int sum=maxSubArray(a,r);
        if(sum>max) max=sum;
    }

    // anti-diagonal
    for(int i=0;i<2*N-1;i++){
        int x=i<N?N-i-1:0;
        int y=i<N-1?0:i-N+1;
        int r=i<N?i+1:2*N-2-i+1;
        for(int j=0;j<r;j++) a[j]=s[N*(y++)+(x++)+1];
        int sum=maxSubArray(a,r);
        if(sum>max) max=sum;
    }

    std::cout << max;
}