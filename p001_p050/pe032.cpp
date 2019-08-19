#include <set>
#include <iostream>
using namespace std;

int sum=0;
set<int> s;

void check(string p,int i,int j,int k){
    int a=atoi(p.substr(i,j).c_str());
    int b=atoi(p.substr(j,k-j).c_str());
    int c=atoi(p.substr(k).c_str());
    if(a==b*c){
        cout << a << " " << b << " " << c << "\n";
        if(s.find(a)==s.end()) {s.insert(a);sum+=a;}
    }
}

void perm(string q,string p=""){
    if(q.length()==0){
        check(p,0,4,5);
        check(p,0,4,6);
    }
    for(int i=0;i<q.length();i++)
        perm(q.substr(0,i)+q.substr(i+1),p+q[i]);        
}    

int main(){
    perm("123456789");
    std::cout << sum;
}