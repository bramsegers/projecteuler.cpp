#include <set>
#include <iostream>
#include "../util/strings.h"
using namespace std;

set<string> logins;

bool valid(string p){
    for(string q:logins){
        int i=p.find(q[0]);
        int j=p.find(q[1]);
        int k=p.find(q[2]);
        if(i>=j || j>=k) return false;
    }
    return true;
}

void search(string c,string p=""){
    int n=c.length();
    if(n==0 && valid(p))
        cout << "passcode found: " << p << "\n";
    for(int i=0;i<n;i++)
        search(c.substr(0,i)+c.substr(i+1),p+c[i]);
}

int main(){
    auto data=readFile("../files/pe079.txt");
    logins=set<string>(data.begin(),data.end());
    string chars="";
    for(string q:logins) for(char c:q)
        if(chars.find(c)==string::npos) chars+=c;

    cout << "#unique logins: " << logins.size() << "\n";
    cout << "unique chars: " << chars << "\n";
    search(chars);
}