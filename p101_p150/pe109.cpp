#include <iostream>

int N=100;

int ways(int k,int i,int t,int* v){
    if(k<0||t<0) return 0;
    if(t==0) return 1;
    int w=0;
    for(int j=i;j>=0;j--)
        w+=ways(k-1,j,t-v[j],v);
    return w;
}

int main(){
    int* v=new int[62]{25,50};
    for(int i=2,s=1;s<=20;s++)
        for(int d=1;d<=3;d++)
            v[i++]=s*d;
    int w=0;
    for(int n=1;n<N;n++)
        for(int s=1;s<=25;s+=(s==20)?5:1)
            w+=ways(2,61,n-2*s,v);
    std::cout << w;
}