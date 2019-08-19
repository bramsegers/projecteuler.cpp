#include <iostream>
using namespace std;

int N=1000000;

void perm(string s,string p=""){
    int n=s.length();
    if(n==0 && --N==0) cout << p << "\n";
    for(int i=0;N>0 && i<n;i++)
        perm(s.substr(0,i)+s.substr(i+1),p+s[i]);
}

int main(){
    perm("0123456789");
}