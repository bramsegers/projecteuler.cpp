#include "../util/strings.h"

int main(){
    auto tri=readFile("../files/pe067.txt");
    vector<int> a;
    for(int i=tri.size()-1;i>=0;i--){
        auto bs=strsplit(tri[i]," ");
        vector<int> b;
        for(int j=0;j<bs.size();j++){
            int k=stoi(bs[j]);
            if(a.size()) k+=max(a[j],a[j+1]);
            b.push_back(k);
        }
        a.swap(b);
    }
    cout << a[0];
}