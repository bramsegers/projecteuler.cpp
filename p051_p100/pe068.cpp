#include <iostream>
#include <string>
using namespace std;

/*

        0
         \         1
          /\      /
        /  5 \   /
      /9      6\/
    / \        /
  /    \8    7/
 4      \----/----2 
         \
          \
           3

*/

string maxstr;

void tostring(string p){
    int n[10];
    for(int i=0;i<10;i++)
        n[i]=p[i]-'0'+1;
    int sum=n[0]+n[5]+n[6];
    if(n[1]+n[6]+n[7]!=sum) return;
    if(n[2]+n[7]+n[8]!=sum) return;
    if(n[3]+n[8]+n[9]!=sum) return;
    if(n[4]+n[9]+n[5]!=sum) return;
    string s="";
    for(int i:{0,5,6,1,6,7,2,7,8,3,8,9,4,9,5})
        s+=to_string(n[i]);
    cout << p << " " << s << "\n";
    if(s.length()==16 && s>maxstr) maxstr=s;
}

void perm(string s,string p=""){
    int n=s.length();
    if(n==0) tostring(p);
    if(n>4 && n<9 && p[9-n]<p[0]) return;
    for(int i=0;i<n;i++) 
        perm(s.substr(0,i)+s.substr(i+1),p+s[i]);
}

int main(){
    perm("0123456789");
    cout << "max:" << maxstr;
}