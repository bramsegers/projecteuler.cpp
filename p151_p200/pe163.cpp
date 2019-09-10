#include <iostream>

int N=36;

int main(){
    long long p=
        (1678*N*N*N
        +3117*N*N
        +88*N
        -345*(N%2)
        -320*(N%3)
        -90*(N%4)
        -288*((N*N*N-N*N+N)%5))
        /240;
    std::cout << p;
}