#include <iostream>

int N=4000000;

int main(){
    int sum=0,f1=1,f2=1; 
    for(int f=0;f<N;){
        if(f%2==0) sum+=f;
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    std::cout<<sum;
}