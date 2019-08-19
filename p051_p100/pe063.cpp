#include <iostream>
#include "../util/infint.h"

int main(){
    int count=0;
    for(int b=1;b<10;b++){
        InfInt p=b,q=b;
        for(int e=1;p.numberOfDigits()==e;e++){
            std::cout << b << "**" << e << "=" << p << "\n";
            count++;
            p*=q;
        }
    }
    std::cout << count << "\n";
}