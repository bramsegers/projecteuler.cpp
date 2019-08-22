#include <map>
#include <algorithm>
#include "../util/primes.h"
using namespace std;

//int N=4;
int N=5;

int concat(int a,int b){
    int m=1;
    while(m<b) m*=10;
    return m*a+b;
}

void search(map<int,vector<int>> &fm,vector<int> &pr,int t,int sum,string path){
    if(t==0) for(auto p:pr)
        printf("%s-%d, sum=%d\n",path.c_str(),p,sum+p);
    else for(auto p:pr){
        vector<int> qr;
        copy_if(pr.begin(),pr.end(),back_inserter(qr),[&](int i){
            return find(fm[p].begin(),fm[p].end(),i)!=fm[p].end();
        });
        if(qr.size()) search(fm,qr,t-1,sum+p,path+"-"+to_string(p));
    }
}

int main(){
    int n=10000;
    auto primes=Primes(n);
    auto pr=primes.vec;
    map<int,vector<int>> fam;
    for(int i=0;i<pr.size();i++){
        int p=pr[i];
        vector<int> qr;
        for(int j=i+1;j<pr.size();j++){
            int q=pr[j];
            if(!primes.get(concat(p,q))) continue;
            if(!primes.get(concat(q,p))) continue;
            qr.push_back(q);
        }
        fam[p]=qr;
    }

    for(int p,i=0;i<pr.size();i++){
        if((p=pr[i])>n) break;
        search(fam,fam[p],N-2,p,to_string(p));
    }
}