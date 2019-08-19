#include <set>
#include <algorithm> 
#include "../util/strings.h"

struct card{int v; int s;};                                                             // value v, suit s

vector<card> parse(vector<string> &h,int i,int j){
    static string v="23456789TJQKA";
    static string s="DHCS";
    vector<card> cards;
    for(int k=i;k<j;k++){
        int va=v.find(h[k][0]);
        int su=s.find(h[k][1]);
        cards.push_back({va,su});
    }
    return cards;
}

int rate(vector<card> &h){

    set<int> ds;                                                                        // distinct suits
    int fv[13]={};                                                                      // frequency of values

    for(auto c:h){
        fv[c.v]++;
        ds.insert(c.s);
    }    

    sort(h.begin(),h.end(),[&](auto& a,auto& b){                                        // sort hand:
        if(fv[b.v]!=fv[a.v]) return fv[b.v]<fv[a.v];                                    // by freq of value desc,                                    
        if(b.v!=a.v) return b.v<a.v;                                                    // by value desc,
        return a.s<b.s;                                                                 // by suit
    });

    if(ds.size()==1 && h[4].v==8)                                           return 9;   // royal flush
    if(ds.size()==1 && h[0].v-h[4].v==4)                                    return 8;   // straight flush
    if(h[0].v==h[3].v)                                                      return 7;   // four of a kind
    if(h[0].v==h[2].v && h[3].v==h[4].v)                                    return 6;   // full house
    if(ds.size()==1)                                                        return 5;   // flush
    if((h[0].v-h[1].v)*(h[1].v-h[2].v)*(h[2].v-h[3].v)*(h[3].v-h[4].v)==1)  return 4;   // straight
    if(h[0].v==h[2].v)                                                      return 3;   // three of a kind
    if(h[0].v==h[1].v && h[2].v==h[3].v)                                    return 2;   // two pairs
    if(h[0].v==h[1].v)                                                      return 1;   // one pair
                                                                            return 0;   // high card
}

bool draw(vector<card> &h1,vector<card> &h2){
    for(int i=0;i<5;i++){
        if(h1[i].v>h2[i].v) return true;
        if(h1[i].v<h2[i].v) return false;
    }
    throw "draw game";
}

int main(){
    int count=0;
    auto lines=readFile("../files/pe054.txt");
    for(string s:lines){
        auto h=strsplit(s," ");
        auto h1=parse(h,0,5);
        auto h2=parse(h,5,10);
        int r1=rate(h1);
        int r2=rate(h2);
        if(r1>r2 || (r1==r2 && draw(h1,h2))) count++;
    }
    cout << count << "\n";
}