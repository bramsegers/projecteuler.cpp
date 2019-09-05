#include <iostream>

void search(long long n,int len,int mask,long long& sum){
    static int a[]={2,3,5,7,11,13,17};
    if(len>3 && (n%1000)%a[len-4]>0) return;
    if(mask+1==1<<10){
        std::cout << n << "\n";
        sum+=n;
        return;
    }
    for(int i=len==0?1:0;i<10;i++)
        if(((mask>>i)&1)==0)
            search(10*n+i,len+1,mask|(1<<i),sum);
}

int main(){
    long long sum=0;
    search(0,0,0,sum);
    std::cout << sum;
}