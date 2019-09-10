#include "../util/gcd.h"
#include <map>
#include <unordered_set>
#include <iostream>

int N=18;

int main(){

    auto C=[](int p,int q){return p<<16|q;};
    auto P=[](int c){return c>>16;};
    auto Q=[](int c){return c&((1<<16)-1);};

    auto parallel=[&](int a,int b){
        int p=P(a)*Q(b)+P(b)*Q(a);
        int q=Q(a)*Q(b);
        int g=gcd(p,q);
        return C(p/g,q/g);
    };

    auto series=[&](int a,int b){
        int q=Q(a)*P(b)+Q(b)*P(a);
        int p=P(a)*P(b);
        int g=gcd(p,q);
        return C(p/g,q/g);
    };

    std::map<int,std::unordered_set<int>> map;
    std::unordered_set<int> all;
    for(int n=1;n<=N;n++){
        std::unordered_set<int> set;
        if(n==1) set.insert(C(1,1));
        for(int j=1;2*j<=n;j++)
            for(int c1:map[j])
                for(int c2:map[n-j]){
                    set.insert(parallel(c1,c2));
                    set.insert(series(c1,c2));
                }
        map[n]=set;
        all.insert(set.begin(),set.end());
        std::cout << n << " " << all.size() << "\n";
    }
}