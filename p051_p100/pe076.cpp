#include <stdio.h>
#include <map>

int N=100;
std::map<int,int> m;

int rec(int a,int b){
    int i=N*a+b;
    if(b<0) return 0;
    if(b==0) return m[i]=1;
    if(!m[i])
        for(int j=1;j<=a;j++)
            m[i]+=rec(j,b-j);
    return m[i];
}

int main(){
    int sum=0;
    for(int i=1;i<N;i++)
        sum+=rec(i,N-i);
    printf("%d\n",sum);
}