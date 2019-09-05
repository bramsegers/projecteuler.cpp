#include "../util/strings.h"

int s[9][9];

bool valid(int r,int c,int n){
    for(int i=0;i<9;i++) 
        if(s[r][i]==n) return 0;
    for(int i=0;i<9;i++) 
        if(s[i][c]==n) return 0;
    int r2=3*(r/3), c2=3*(c/3);
    for(int i=r2;i<r2+3;i++) 
        for(int j=c2;j<c2+3;j++)
            if(s[i][j]==n) return 0;
    return 1;
}

int solve(int i){
    if(i==81) return 100*s[0][0]+10*s[0][1]+s[0][2];
    int r=i/9, c=i%9, v=0;
    if(s[r][c]) v+=solve(i+1);
    else for(int n=1;n<10;n++)
        if(valid(r,c,n)){
            s[r][c]=n;
            v+=solve(i+1);
            s[r][c]=0;
        }
    return v;
}

int main(){
    int sum=0;
    auto data=readFile("../files/pe096.txt");
    for(int i=1;i<data.size();i+=10){
        for(int j=0;j<9;j++)
            for(int k=0;k<9;k++)
                s[j][k]=data[i+j][k]-'0';
        sum+=solve(0);
    }
    cout << sum;
}