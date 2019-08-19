#include <stdio.h>

int N[]={1,10,100,1000,10000,100000,1000000};

int main(){
    int prod=1,i=0,t=10,d=1,c=0;
    int done=0,len=sizeof(N)/sizeof(*N);
    while(done<len){
        if(++i==t) {t*=10;d++;}
        if((c+=d)>=N[done]){
            int j=i,k=0,p=0;
            while(k<c-N[done]+1){
                p=j%10;
                j/=10;
                k++;
            }
            prod*=p;
            done++;
        }
    }
    printf("%d\n",prod);
}