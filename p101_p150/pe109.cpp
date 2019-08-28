#include <vector>
#include <iostream>

int N=100;

int ways(int k,int i,int t,std::vector<int> &v){
    if(k<0||t<0) return 0;
    if(t==0) return 1;
    int w=0;
    for(int j=i;j>=0;j--)
        w+=ways(k-1,j,t-v[j],v);
    return w;
}

int main(){
    std::vector<int> v={25,50};
    for(int s=1;s<=20;s++)
        for(int d=1;d<=3;d++)
            v.push_back(s*d);
    int w=0;
    for(int n=1;n<N;n++)
        for(int s=1;s<=25;s+=(s==20)?5:1)
            w+=ways(2,v.size()-1,n-2*s,v);
    std::cout << w;
}