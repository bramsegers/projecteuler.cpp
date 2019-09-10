#include <math.h>
#include <set>
#include <vector>
#include <iostream>

int maxreach=0;

double operate(double d1,double d2,int op){
    if(op==0) return d1-d2;
    if(op==1) return d1/d2;
    if(op==2) return d1+d2;
              return d1*d2;
}

void evaluate(std::vector<double>& v,std::set<int>& reach){
    if (v.size()==1){
        int i=round(v[0]);
        if(abs(v[0]-i)<.00001) reach.insert(i);
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(i==j) continue;
            double a=v[i],b=v[j];
            auto v2(v);
            v2.erase(v2.begin()+i);
            v2.erase(v2.begin()+j-1);
            for(int op=0;op<4;op++){
                auto v3(v2);
                v3.push_back(operate(a,b,op));
                evaluate(v3,reach);
                if(op<2){
                    auto v4(v2);
                    v4.push_back(operate(b,a,op));
                    evaluate(v4,reach);
                }
            }
        }
    }
}

void gen_digits(int t,int d,double* s){
    if(t==4){
        std::vector<double> v(s,s+4);
        std::set<int> reach;
        evaluate(v,reach);
        int n=0;
        while(reach.find(n+1)!=reach.end()) n++;
        if(n>maxreach){
            maxreach=n;
            std::cout<<s[0]<<s[1]<<s[2]<<s[3]<<' '<<n<<'\n';
        }
    }
    else for(int i=d;i<10;i++){
        s[t]=i;
        gen_digits(t+1,i+1,s);
    }
}

int main(){
    gen_digits(0,1,new double[4]);
}