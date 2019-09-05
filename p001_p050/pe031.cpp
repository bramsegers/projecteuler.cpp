#include <iostream>

int ways(int i,int left){
    static int coins[]={200,100,50,20,10,5,2,1};
    int rv=(left==0)?1:0;
    for(int j=i;j<8;j++)
        if(left>=coins[j])
            rv+=ways(j,left-coins[j]);
    return rv;
}

int main(){
    std::cout << ways(0,200);
}