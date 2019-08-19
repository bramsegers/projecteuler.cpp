#include <stdio.h>

int concat(int p,int i){
    int m=1;
    while(m<i) m*=10;
    return m*p+i;
}

bool pandigital(int p){
    int set=0;
    while(p>0){
        set|=1<<(p%10);
        p/=10;
    }
    return set==(1<<10)-2;
}

int main(){
    int max=0;
    for(int i=1;i<10000;i++){
        for(int p=0,n=1;;n++){
            p=concat(p,n*i);
            if(p>1000000000) break;
            if(pandigital(p)){
                printf("%d->%d: %d\n",i,n,p);
                if(p>max) max=p;
            }
        }
    }
    printf("%d\n",max);
}