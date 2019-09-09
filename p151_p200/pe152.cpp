#include "../util/gcd.h"
#include <iostream>

//int N=45;
int N=80;

int search(long long todo,long long done,int n,int* P, int* T, int len){
    if(todo<0) return 0;
    if(!todo) return 1;
    int rv=0;
    if(todo<=done+T[n] && ++n<len){
        rv+=search(todo-P[n],done+P[n],n,P,T,len);
        rv+=search(todo,done,n,P,T,len);
    }
    return rv;
}

int main(){
    int D[]={2,3,4,5,6,7,8,9,10,12,13,14,15,18,20,21,24,
             28,30,35,36,39,40,42,45,52,56,60,63,70,72};
    long long LCM=1;
    int len=sizeof(D)/sizeof(*D);
    for(int i=0;i<len;i++){
        if(D[i]>N) len=i;
        else LCM=lcm(LCM,D[i]*D[i]);
    }
    int* P=new int[len];
    int* T=new int[len];
    for(int i=len-1;i>=0;i--){
        P[i]=LCM/(D[i]*D[i]);
        T[i]=(i==len-1)?0:T[i+1]+P[i+1];
    }
    int count=search(LCM/2-P[0]-P[1],P[1],1,P,T,len);
    std::cout << count;
}