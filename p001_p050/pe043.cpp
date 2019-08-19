#include <iostream>
using namespace std;

long long sum=0;
int a[]={2,3,5,7,11,13,17};

long long tolong(string s){
    long long rv=0;
    for(auto c:s)
        rv=10*rv+c-'0';
    return rv;
}

void perm(string s,string p=""){
    int n=s.length();
    if(n==9 && p[0]=='0') return;
    for(int i=4;i<=10;i++)
        if(n+i==10 && tolong(p.substr(i-3,3))%a[i-4]>0)
            return;
    if(n==0){
        cout << p << "\n";
        sum+=tolong(p);
    }
    for(int i=0;i<n;i++)
        perm(s.substr(0,i)+s.substr(i+1),p+s[i]);
}

int main(){
    perm("1234567890");
    cout << "sum:" << sum << "\n";
}