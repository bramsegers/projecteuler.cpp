#include <iostream>
using LL=long long;

LL f(LL n,LL d){
    LL p=0,q=0,r=1e18,s,t,v;
    for(LL i=18;i>0;i--){
        s= r/10;
        t= n/r;
        v= i*s;
        q+=t*v;
        q+=t*p*r;
        n-=t*r;
        if(d<t) q+=r;
        if(d==t) p++;
        r=s;
    }
    q+=p*(n+1);
    if(d<=n) q++;
    return q;
}

LL sum(LL d,LL a,LL b){
    LL fa=f(a,d);
    LL fb=f(b,d);
    LL m=(a+b)/2;
    if(a==b && a==fa) return a;
    if(a==b || fa>b || fb<a) return 0;
    return sum(d,a,m)+sum(d,m+1,b);
}

int main(){
    LL SUM=0;
    for(LL d=1;d<10;d++){
        LL s=sum(d,0,1e18);
        SUM+=s;
        std::cout << d << " " << s << "\n";
    }
    std::cout << SUM;
}