#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include "../util/strings.h"

string pattern(string s){
    static string abc="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<s.length();i++)
        s=replaceAll(s,string(1,s[i]),string(1,abc[i]));
    return s;
}

int get_max(string& w1,string& w2,set<string>& sq){
    int max=0;
    string p1=pattern(w1);
    for(string s1:sq)
        if(p1==pattern(s1)){
            string s2=w2;
            for(int i=0;i<w1.length();i++)
                s2[s2.find(w1[i])]=s1[i];
            if(sq.find(s2)!=sq.end()){
                int i1=stoi(s1);
                int i2=stoi(s2);
                if(i1>max) max=i1;
                if(i2>max) max=i2;
                cout << w1 << " " << w2 << " " << s1 << " " << s2 << "\n";
            }
        }
    return max;
}

int main(){
    int maxnum=0;
    auto data=readFile("../files/pe098.txt");
    auto words=strsplit(replaceAll(data[0],"\"",""),",");
    map<string,vector<string>> mwords;
    map<int,set<string>> msquares;
    for(string w:words){
        string s=w;
        sort(s.begin(),s.end());
        mwords[s].push_back(w);
    }
    for(auto &pair:mwords){
        string key=pair.first;
        int wlen=mwords[key].size();
        if(wlen==1) continue;
        int len=key.length();
        if(msquares.find(len)==msquares.end()){
            long long b=pow(10LL,0.5*(len-1))+0.5;
            if((len&1)==0) b++;
            long long c=pow(10,len);
            while(b*b<c){
                msquares[len].insert(to_string(b*b));
                b++;
            }
        }
        for(int i=0;i<wlen;i++){
            for(int j=i+1;j<wlen;j++){
                int n=get_max(mwords[key][i],mwords[key][j],msquares[len]);
                if(n>maxnum) maxnum=n;
            }
        }
    }
    cout << maxnum;
}