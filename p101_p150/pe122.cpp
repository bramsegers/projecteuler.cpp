#include <iostream>

int N=200;

int solve(int i,int n,int& len,int* a){
	if(i>=len) return len;
    if(a[i]==n) len=i;
     else for(int j=i;j>=0;j--)
        if(a[i]+a[j]<=n){
            a[i+1]=a[i]+a[j];
            solve(i+1,n,len,a);
        }
	return len;
}

int main(){
    int sum=0;
	int* a=new int[N]{1};
	for(int len,n=1;n<=N;n++){
		solve(0,n,len=N,a);
		sum+=len;
	}
    std::cout << sum;
}