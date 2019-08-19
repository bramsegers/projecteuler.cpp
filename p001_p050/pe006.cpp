#include <iostream>

int N=100;

int main(){
    int ans=N*(N+1)*(3*N*N-N-2)/12;
    std::cout << ans;
}