#include <iostream>

int N=1000;

int main(){

    // generate sum triangle
    int* a=new int[N*(N+3)/2];
    long long sum=0,t=0;
    for(int r=0,c=0,k=1;k<=N*(N+1)/2;k++){
        t=(615949*t+797807)%1048576;
        sum+=t-524288;
        a[k+r]=sum;
        if(++c>r){
            r++;
            c=0;
            sum=0;
        }
    }

    // generate minimal sum
    long long min=1LL<<62;
    for(int i=1;i<=N;i++)
        for(int m,k,j=1;j<=i;j++)
            for(sum=0,k=i;k<=N;k++){
                m=k*(k+1)/2-1;
                sum+=a[m+j+k-i]-a[m+j-1];
                if(sum<min) min=sum;
            }
    std::cout << min;
}