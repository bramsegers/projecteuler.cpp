#include <cstdio>

int N=1000;

int main(){
    int a,b,c;
    for(a=1;3*a<N;a++)
        for(b=a+1;b<(c=N-a-b);b++)
            if(a*a+b*b==c*c)
                printf("(a,b,c)=(%d,%d,%d)\nabc=%d",a,b,c,a*b*c);
}