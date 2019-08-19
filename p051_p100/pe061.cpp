#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

map<int,vector<int>> P;

int poly(int i,int n){
    if(i==3) return n*(n+1)/2;
    if(i==4) return n*n;
    if(i==5) return n*(3*n-1)/2;
    if(i==6) return n*(2*n-1);
    if(i==7) return n*(5*n-3)/2;
    if(i==8) return n*(3*n-2);
}

void search(string &p,int a,int b,int s,int i){
    for(int n:P[p[i]-'0'])
        if(b%100==n/100)
            if(i<4) search(p,a,n,s+n,i+1);
            else if(n%100==a/100) cout << s+n << "\n";
}

void perm(string s,string p=""){
    int n=s.length();
    if(n==0) for(int i:P[3])
        search(p,i,i,i,0);
    for(int i=0;i<n;i++)
        perm(s.substr(0,i)+s.substr(i+1),p+s[i]);
}

int main(){
    for(int i=3;i<=8;i++)
        for(int p,n=1;(p=poly(i,n))<10000;n++)
            if(p>=1000) P[i].push_back(p);    
    perm("45678");
}