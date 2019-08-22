#include <iostream>

int N=10000000;

bool permutation(int n1,int n2){
    int a[10]={};
    int b[10]={};
    while(n1>0) {a[n1%10]++;n1/=10;}
    while(n2>0) {b[n2%10]++;n2/=10;}
    for(int i=0;i<10;i++)
        if(a[i]!=b[i]) return false;
    return true;
}

int main(){
	int* phi=new int[N];
	for(int n=1;n<N;n++)
        phi[n]=n;
    for(int p=2;p<N;p++){
		if(phi[p]==p){
			phi[p]=p-1;
			for(int n=2*p;n<N;n+=p)
				phi[n]=(phi[n]/p)*(p-1);
        }
    }
	int minn;
	double minr=N;
	for(int n=2;n<N;n++)
		if(permutation(n,phi[n])){
			double r=(double)n/phi[n];
			if(r<minr) {minr=r,minn=n;}
		}
	std::cout << minn;
}