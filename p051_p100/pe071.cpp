#include <stdio.h>
using LL=long long;

LL n=3, d=7;
LL N=1000000;

int main(){
    LL n2=0,d2=1;
	for(LL i=N;i>1;i--){
    	LL c=n*i/d;
		if(c*d2>=i*n2 && i%d>0){
			n2=c;
			d2=i;
		}
    }
	printf("%lld/%lld\n",n2,d2);
}