#include <map>
#include <vector>
#include <iostream>

int R=1000000000;
int D=7;

int main(){
    std::map<int,std::vector<long long>> A;
    for(int i=0,p=1;p<R;i++,p*=D)
        for(int j=0;j<=D;j++){
            A[i].push_back(j*(j+1)/2);
            if(i>0) A[i][j]*=A[i-1][D];
        }
    long long count=0;
    for(int i=0;R;i++){
        int mod=R%D;
        count*=mod+1;
        count+=A[i][mod];
        R/=D;
    }
    std::cout << count;
}