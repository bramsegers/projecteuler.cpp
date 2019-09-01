#include <iostream>

int A=3;
int B=1000;

int main(){
    int sum=0;
    for(int a=A;a<=B;a++)
        sum+=((a-1)/2)*2*a;
    std::cout << sum;
}