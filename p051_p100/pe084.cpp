#include <stdio.h>
#include <time.h>
#include <random>
#include <algorithm>

//int D=6;
int D=4;

int CC(int loc){
    static int cc[]={0,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    static int i=0;
    int c=cc[i];
    if(++i==16) i=0;
    return c<0?loc:c;
}

int CH(int loc){
    static int ch[]={0,10,11,24,39,5,107,108,109,110,-1,-1,-1,-1,-1,-1};
    static int i=0;
    int c=ch[i];
    if(++i==16) i=0;
    if(c<100) return c<0?loc:c;
    if(c==107 || c==108) return loc==7?15:(loc==22?25:5);
    if(c==109) return loc==7?12:(loc==22?28:12);
    return loc==7?4:(loc==22?19:CC(33));
}

int main(){
    srand(time(0));
    int loc=0;
    int doubles=0;
    int rep=100000000;
    int freq[40]={};
    for(int r=0;r<rep;r++){
        int d1=rand()%D+1;
        int d2=rand()%D+1;
        doubles=(d1==d2)?doubles+1:0;
        if(doubles==3){
            doubles=0;
            loc=10;
        }else{
            loc+=d1+d2;
            loc=loc%40;
            if(loc==30) loc=10;
            else if(loc==2 || loc==17 || loc==33) loc=CC(loc);
            else if(loc==7 || loc==22 || loc==36) loc=CH(loc);
        }
        freq[loc]++;
    }

    struct M{int idx;int freq;};
    M m[40];
    for(int i=0;i<40;i++)
        m[i]={i,freq[i]};

    std::sort(m,m+40,[](auto& a,auto& b){
        return b.freq<a.freq;
    });

    for(int i=0;i<3;i++){
        if(m[i].idx<10) printf("%d",0);
        printf("%d",m[i].idx);
    }
}