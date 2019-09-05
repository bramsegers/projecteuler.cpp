#include "../util/infint.h";
#include <iostream>
#include <set>

int N=100;

InfInt pow(int b,int e){
    InfInt f=1;
    for(int i=0;i<e;i++) f*=b;
    return f;
}

int main(){
    std::set<InfInt> set;
    for(int a=2;a<=N;a++)
        for(int b=2;b<=N;b++)
            set.insert(pow(a,b));
    std::cout << set.size();
}