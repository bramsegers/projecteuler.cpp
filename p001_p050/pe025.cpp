#include "../util/infint.h"
#include <iostream>

int N=1000;

int main(){
    auto f1=InfInt(1);
    auto f2=InfInt(1);
    for(int i=3;;i++){
        auto f=f1+f2;
        if(f.numberOfDigits()>=N){
            std::cout << i;
            break;
        }
        f1=f2;
        f2=f;
    }
}