#include <vector>
#include <algorithm>
#include <iostream>

int N=1000000;

int main(){

    int* divSum=new int[N];
    for(int i=1;i<N;i++)
        for(int j=i*2;j<N;j+=i)
            divSum[j]+=i;

    int maxNum=0;
    int maxLen=0;
    std::vector<int> v;
    for(int i=2;i<N;i++){
        int last=i;
        while(last<N && std::find(v.begin(),v.end(),last)==v.end()){
            v.push_back(last);
            last=divSum[last];
        }
        if(last==v[0]){
            if(v.size()>maxLen){
                maxLen=v.size();
                maxNum=i;
            }
        }
        v.clear();
    }
    printf("max len: %d\n",maxLen);
    printf("smallest member: %d\n",maxNum);
}