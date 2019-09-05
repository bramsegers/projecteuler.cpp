#include "../util/strings.h"
#include <iostream>

bool valid(int* a,int n){
    for(int c,d,p,s,e,b,k,j=1;j<(1<<n);j++){
        for(b=0,k=0;k<n;k++) b+=(j>>k)&1;
        for(c=1;c<(1<<b)-1;c++){
            for(p=0,s=0,e=0,d=0;d<n;d++){
                if(!((j>>d)&1)) continue;
                p+=(c>>e)&1?-1:1;
                s+=(c>>e)&1?-a[d]:a[d];
                e++;
            }
            if(s==0||(p>0 && s<=0)) return 0;
        }
    }
    return 1;
}

int main(){
    int c=0;
    for(auto s:readFile("../files/pe105.txt")){
        auto t=strsplit(s,",");
        int sum=0,n=t.size(),a[n];
        for(int i=0;i<n;i++){
            a[i]=stoi(t[i]);
            sum+=a[i];
        }
        if(valid(a,n)) c+=sum;
    }
    std::cout << c;
}