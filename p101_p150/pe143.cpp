#include "../util/gcd.h"
#include <map>
#include <set>
#include <iostream>

int N=120000;

int main(){
    std::map<int,std::set<int>> map;
    for(int m=1;m*m<=N;m++)
        for(int n=1;n<m && m*(2*n+m)<=N;n++)
            if((m-n)%3 && gcd(m,n)==1){
                int a=(2*m*n)+(n*n);
                int b=(m*m)-(n*n);
                if(a>b) std::swap(a,b);
                for(int m=1;m*(a+b)<=N;m++)
                    map[m*a].insert(m*b);
            }

    int sum=0;
    std::set<int> set;
    for(auto& e:map){
        int p=e.first;
        auto& s=e.second;
        std::set<int>::iterator it1,it2;
        for(it1=s.begin();it1!=s.end();it1++)
            for(it2=it1;++it2!=s.end();){
                int q=*it1,r=*it2;
                if(p+q+r>N) continue;
                if(!map.count(q)) continue;
                if(map[q].find(r)==map[q].end()) continue;
                if(set.find(p+q+r)!=set.end()) continue;
                set.insert(p+q+r);
                sum+=p+q+r;
            }
    }
    std::cout << sum;
}