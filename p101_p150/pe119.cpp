#include "../util/infint.h"
#include <iostream>
#include <set>

int N=30;

int main(){
    std::set<InfInt> set;
    for(int e,b=2;b<100;b++){
        InfInt n=b;
        for(int e=2;e<100;e++){
            n*=b;
            int sum=0;
            for(int i=0;i<n.numberOfDigits();i++)
                sum+=n.digitAt(i);
            if(sum==b) set.insert(n);
        }
    }
    auto it=set.begin();
    std::advance(it,N-1);
    std::cout << *it;
}