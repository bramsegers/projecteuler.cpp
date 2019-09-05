#include <stdio.h>

int b1=2;
int b2=10;
int N=1000000;

bool palindrome(int n,int b){
    static int i,j,a[32];
    for(i=0;n>0;i++){
        a[i]=n%b;
        n/=b;
    }
    for(j=0;2*j<i;j++) 
        if(a[j]!=a[i-j-1]) return false;
    return true;
}

int main(){
    int sum=0;
    for(int n=1;n<N;n++){
        if(!palindrome(n,b1)) continue;
        if(!palindrome(n,b2)) continue;
        printf("%d\n",n);
        sum+=n;
    }
    printf("sum:%d\n",sum);
}