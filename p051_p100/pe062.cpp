#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//int N=3;
//int N=4;
int N=5;

int main(){
    struct pair{long long i;long long j;};
    map<string,vector<pair>> C;
    for(long long i=1;;i++){
        long long c=i*i*i;
        string s=to_string(c);
        sort(s.begin(),s.end()); 
        C[s].push_back({i,c});
        if(C[s].size()==N){
            for(auto c:C[s])
                cout << c.i << " " << c.j << "\n";
            return 0;
        }
    }
}