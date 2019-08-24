#include "../util/strings.h"

int main(){

    auto data=readFile("../files/pe082.txt");
    int N=data.size(), A[N][N], B[N][N];
    for(int j=0;j<N;j++){
        auto s=strsplit(data[j],",");
        for(int i=0;i<N;i++)
            A[j][i]=stoi(s[i]);
        B[j][0]=A[j][0];
    }

    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            for(int k=j-1;k>0;k--)
                if(A[k][i]+B[k+1][i]<B[k][i])
                    B[k][i]=A[k][i]+B[k+1][i];
            for(int k=j+1;k<N;k++)
                if(A[k][i]+B[k-1][i]<B[k][i])
                    B[k][i]=A[k][i]+B[k-1][i];
        }
        for(int j=0;j<N;j++)
            B[j][i+1]=B[j][i]+A[j][i+1];
    }

    int min=1<<30;
    for(int j=0;j<N;j++)
        if(B[j][N-1]<min) min=B[j][N-1];
    cout << min << "\n";

}