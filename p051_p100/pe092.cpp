#include <iostream>

int N=10000000;

int main(){
    
    int * mem=new int[N]{};
    int * add=new int[100];
    mem[1]=1;
    mem[89]=89;
    
    for(int n=1;n<N;n++){
        add[0]=n;
        int i=n,k=1,j;
        while(!mem[i]){
            add[k++]=i;
            for(j=i,i=0;j>0;j/=10)
                i+=(j%10)*(j%10);
        }
        for(j=0;j<k;j++)
            mem[add[j]]=mem[i];
    }

    int count=0;
    for(int i=0;i<N;i++)
        count+=(mem[i]==89);
    std::cout << count;
}