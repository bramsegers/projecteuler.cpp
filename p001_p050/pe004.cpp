#include <stdio.h>

bool palindrome(int s){
    static int i,a[6];
    for(i=0;s>0;s/=10)
        a[i++]=s%10;
    for(int j=0;2*j<i;j++)
        if(a[j]!=a[i-j-1]) return 0;
    return 1;
}

int main(){
    int max=0;
    for(int p,i=100;i<1000;i++)
        for(int j=100;j<1000;j++)
            if((p=i*j)>max && palindrome(p))
                printf("%d %d %d\n",i,j,max=p);
}
