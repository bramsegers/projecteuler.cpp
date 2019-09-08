#include <iostream>

int X=43;
int Y=47;

int straight(int c,int r,int i,int j){
    return (c-i+1)*(r-j+1);
}

int cross(int C,int R,int i,int j){
    int count=0;
    for(int r=0;r<=R;r+=2)
        for(int c=2;c<=C;c+=2)
            count+=(c-i>=0 && c+j<=C && r+i+j<=R)
            +(c-i-1>=0 && c+j-1<=C && r+i+j+1<=R);
    return i==j?count:2*count;
}

int main(){
    if(X>Y) std::swap(X,Y);
    int sum=0;
    for(int R=1;R<=Y;R++)
        for(int C=1;C<=X && (C<=R || R>X);C++){
            for(int r=1;r<=R;r++)
                for(int c=1;c<=C;c++)
                    sum+=(R>X || C==R?1:2)*straight(C,R,c,r);   
            for(int r=1;r<2*(R<C?R:C);r++)
                for(int c=1;c<=r;c++)
                    sum+=(R>X || C==R?1:2)*cross(2*C,2*R,c,r);
        }
    std::cout << "sum:" << sum;
}