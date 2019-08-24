#include <iostream>

int n=3, d=7;
int N=1000000;

int main(){
	long long i,c,n2=0,d2=1;
	for(i=N;i>1;i--){
		c=i*n/d;
		if(c*d2>=i*n2 && i%d>0){
			n2=c;
			d2=i;
		}
	}
	std::cout << n2 << "/" << d2 << "\n";
}