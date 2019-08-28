#include <vector>
#include <iostream>

std::vector<int> dice;

void gen_dice(int s,int p,int d){
    if(s==0){
        if(d&(1<<6)) d|=1<<9;
        if(d&(1<<9)) d|=1<<6;
        dice.push_back(d);
        return;
    }
    for(int q=p;q<10;q++)
        gen_dice(s-1,q+1,d|(1<<q));
}

bool all_squares(int a,int b){
    for(int n=1;n<10;n++){
        int d1=(n*n)/10;
        int d2=(n*n)%10;
        bool a1=a&(1<<d1);
        bool a2=a&(1<<d2);
        bool b1=b&(1<<d1);
        bool b2=b&(1<<d2);
        bool c1=a1 && b2;
        bool c2=a2 && b1;
        if(!c1 && !c2) return 0;
    }
    return 1;
}

int main(){
    gen_dice(6,0,0);
    int count=0;
    for(int i=0;i<dice.size();i++)
        for(int j=i;j<dice.size();j++)
            count+=all_squares(dice[i],dice[j]);
    std::cout << count;
}