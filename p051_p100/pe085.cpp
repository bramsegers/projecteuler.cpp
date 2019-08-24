#include <stdio.h>
#include <vector>
#include <algorithm>

int N=2000000;

int rectangles(int x,int y){
    int sum=0;
    for(int j=1;j<=y;j++)
        for(int i=1;i<=x;i++)
            sum+=(1+x-i)*(1+y-j);
    return sum;
}

int main(){

    struct entr{int x;int y;int rects;int diff;int area;};
    std::vector<entr> v;

    for(int d0,d1,x=2,y=1;x>y;y++){
        for(x=0,d1=N,d0=N+1;d0>d1;){
            x++;
            d0=d1;
            d1=abs(N-rectangles(x,y));
        }
        int r=rectangles(--x,y);
        int d=abs(N-r);
        v.push_back({x,y,r,d,x*y});
    }

    std::sort(v.begin(),v.end(),[](entr& a,entr& b){
        return b.diff>a.diff;
    });
    printf("%d\n",v[0].area);
}