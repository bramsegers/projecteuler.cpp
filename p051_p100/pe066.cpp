#include <iostream>
#include <vector>
#include <math.h>
#include "../util/infint.h"
using namespace std;

int N=1000;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int dMax=0;
    InfInt xMax=0;
    for(int D=2;D<=N;D++){
        double s=sqrt(D);
        int b=s;
        if(b*b==D) continue;
        vector<int> cf;
        int m,a=1,a0=a,b0=b;
        for(m=1;;m++){
            int c=D-b*b;
            int g=gcd(a,c);
            a/=g;
            c/=g;
            int d=(int)((s+b)*a/c);
            int e=(d*c/a)-b;
            a=c;
            b=e;
            cf.push_back(d);
            if(a==a0 && b==b0) break;
        }
        int n=((m&1)+1)*m-1;
        InfInt num=1;
        InfInt den=cf[(n-1)%m];
        for(int i=n-2;i>=0;i--){
            num+=den*cf[i%m];
            auto tmp=num;
            num=den;
            den=tmp;
        }
        num+=den*b;
        if(num>xMax){
            xMax=num;
            dMax=D;
        }
    }
    cout << "x max : " << xMax << "\n";
    cout << "D max : " << dMax << "\n";
}