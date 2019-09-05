#include <set>
#include <iostream>

int sum=0;
std::set<int> s;

void check(int a,int b,int c){
    if(a==b*c){
        std::cout << a << " " << b << " " << c << "\n";
        if(s.find(a)==s.end()) {s.insert(a);sum+=a;}
    }
}

void perm(int n,int mask){
    if(mask+2==1<<10){
        check(n/100000,(n/1000)%100,n%1000);
        check(n/100000,(n/10000)%10,n%10000);
    }
    for(int i=1;i<10;i++)
        if(((mask>>i)&1)==0)
            perm(10*n+i,mask|(1<<i));
}

int main(){
    perm(0,0);
    std::cout << sum;
}