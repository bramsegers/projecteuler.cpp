#include "../util/strings.h"
#include <algorithm>
#include <iostream>

int main(){
    auto rows=readFile("../files/pe107.txt");
    struct edge{int w;int x;int y;};
    vector<long long> vertices;
    vector<edge> edges;
    int weight=0;

    for(int i=0;i<rows.size();i++){
        vertices.push_back(1LL<<i);
        auto row=strsplit(rows[i],",");
        for(int j=0;j<i;j++)
            if(row[j]!="-"){
                int w=stoi(row[j]);
                edges.push_back({w,j,i});
                weight+=w;
            }
    }

    sort(edges.begin(),edges.end(),[](edge& a,edge& b){
        if(a.w!=b.w) return a.w<b.w;
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
    });

    for(int j,k,i=0;vertices.size()>1;i++){
        for(j=0;;j++) if((vertices[j]>>edges[i].x)&1) break;
        for(k=0;;k++) if((vertices[k]>>edges[i].y)&1) break;
        if(j==k) continue;
        vertices[j]=vertices[j]|vertices[k];
        vertices.erase(vertices.begin()+k);
        weight-=edges[i].w;
    }
    std::cout << weight;
}