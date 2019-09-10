#include "../util/strings.h"
#include <math.h>
#include <iostream>
using LL = long long;

LL N=1000;

string TO19[]={
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

string TENS[]={
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

string DENOM[]={
    "",
    "thousand",
    "million",
    "billion",
    "trillion"
};

string to2Word(LL val){
    if(val<20) return TO19[val];
    LL length=sizeof(TENS)/sizeof(*TENS);
    for(LL v=0;v<length;v++){
        string dcap=TENS[v];
        LL dval=20+10*v;
        if(dval+10>val){
            if(val%10!=0)
                return dcap+'-'+TO19[val%10];
            return dcap;
        }
    }
    return "";
}

string to3Word(LL val){
    string word="";
    LL rem=val/100;
    LL mod=val%100;
    if(rem>0){
        word=TO19[rem]+" hundred";
        if(mod>0) word+=" and ";
    }
    if(mod>0) word+=to2Word(mod);
    return word;
}

string toWord(LL val){
    if(val<100) return to2Word(val);
    if(val<1000) return to3Word(val);
    LL length=sizeof(DENOM)/sizeof(*DENOM);
    for(LL v=0;v<length;v++){
        LL didx=v-1;
        LL dval=pow(1000,v);
        if(dval>val){
            LL mod=pow(1000,didx);
            LL l=val/mod;
            LL r=val-(l*mod);
            string ret=to3Word(l)+' '+DENOM[didx];
            if(r>0) ret+=", "+toWord(r);
            return ret;
        }
    }
    return "";
}

int main(){
    LL sum=0;
    for(LL val=1;val<=N;val++){
        string s=toWord(val);
        s=replaceAll(s," ","");
        s=replaceAll(s,"-","");
        LL len=s.size();
        cout << "(" << len << ") " <<s << "\n";
        sum+=len;
    }
    cout << sum;
}