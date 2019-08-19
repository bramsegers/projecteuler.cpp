#include <iostream>

int N=1000;

int main(){
    int maxlen=0,maxn;
	for(int n=2;n<N;n++){
		int r=1;
        for(int i=0;i<n;i++) 
            r=(r*10)%n;
		int r0=r,len=0;
		while(len==0||r!=r0){
            r=(r*10)%n;
			len++;
        }
        if(len>maxlen){
			maxn=n;
			maxlen=len;
		}
    }
    std::cout << maxn;
}