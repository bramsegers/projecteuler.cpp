#include <iostream>

int N=1000000;

int main(){
	int* phi=new int[N+1];
	for(int n=1;n<=N;n++)
        phi[n]=n;
    for(int p=2;p<=N;p++){
		if(phi[p]==p){
			phi[p]=p-1;
			for(int n=2*p;n<=N;n+=p)
				phi[n]=(phi[n]/p)*(p-1);
        }
    }
	int maxn;
	double maxr=0;
	for(int n=1;n<=N;n++){
		double r=(double)n/phi[n];
		if(r>maxr) {maxr=r,maxn=n;}
	}
	std::cout << maxn;
}