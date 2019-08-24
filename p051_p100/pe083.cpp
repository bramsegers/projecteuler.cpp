#include "../util/strings.h"
#include "../util/dijkstra.h"

int main(){

    auto data=readFile("../files/pe083.txt");
    int N=data.size(), A[N][N];
    for(int j=0;j<N;j++){
        auto s=strsplit(data[j],",");
        for(int i=0;i<N;i++)
            A[j][i]=stoi(s[i]);
    }

    Graph g(N*N);
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if(j>0)   g.addEdge(N*j+i, N*(j-1)+i, A[j-1][i]);
            if(i>0)   g.addEdge(N*j+i, N*j+(i-1), A[j][i-1]);
            if(j<N-1) g.addEdge(N*j+i, N*(j+1)+i, A[j+1][i]);
            if(i<N-1) g.addEdge(N*j+i, N*j+(i+1), A[j][i+1]);
        }
    }

    int s=g.shortestPath(0)[N*N-1];
    cout << (s+A[0][0]);
}