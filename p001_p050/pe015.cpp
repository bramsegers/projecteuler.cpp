#include <iostream>
#include "../util/infint.h"

int N=20;
int M=20;

InfInt fac(InfInt n){
    InfInt f=1;
    for(InfInt i=2;i<=n;++i)
        f*=i;
    return f;
}

int main(){
    auto a=InfInt(N);
    auto b=InfInt(M);
    auto ans=fac(a+b)/(fac(a)*fac(b));
    std::cout << ans;
}