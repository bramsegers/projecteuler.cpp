#include <math.h>
#include <stdio.h>

double pentagonal(int n){
    int a=(int)((0.5+sqrt(0.25+6*n))/3);
    return a*(3*a-1)/2==n;
}

int main(){
    int len=0;
    int* p=new int[4000];
    for(int i=1;;i++){
        int p2=(i*((3*i)-1)/2);
        for(int j=0;j<len;j++){
            int p1=p[j];
            if(pentagonal(p2+p1) && pentagonal(p2-p1)){
                printf("P(j)=%d, P(k)=%d, P(k)-P(j)=%d\n",p1,p2,p2-p1);
                return 0;
            }
        }
        p[len++]=p2;
    }
    
}