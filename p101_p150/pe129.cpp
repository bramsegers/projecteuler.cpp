#include <iostream>

int N=1000000;

int main(){
    int n=N+(N&1)-1,a=0,d;
    while(a<=N)
        if((n+=2)%5>0)
            for(a=1,d=1;d;a++) 
                d=(d*10+1)%n;
    std::cout << n;
}