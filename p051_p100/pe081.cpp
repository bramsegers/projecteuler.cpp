#include "../util/strings.h"

int main(){

    auto data=readFile("../files/pe081.txt");
    int N=data.size(), A[N][N];
    for(int j=0;j<N;j++){
        auto s=strsplit(data[j],",");
        for(int i=0;i<N;i++)
            A[j][i]=stoi(s[i]);
    }

    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if(i==0&&j==0) continue;
            int b=j>0?A[j-1][i]:1<<30;
            int c=i>0?A[j][i-1]:1<<30;
            A[j][i]+=b<c?b:c;
        }
    }

    cout << A[N-1][N-1] << "\n";

}