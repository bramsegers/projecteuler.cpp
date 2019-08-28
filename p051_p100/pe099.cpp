#include <math.h> 
#include "../util/strings.h"

int main(){
    auto nums=readFile("../files/pe099.txt");
    int maxLine, maxExp=0;
    for(int i=0;i<nums.size();i++){
        auto n=strsplit(nums[i],",");
        double a=stod(n[0]);
        double b=stod(n[1]);
        double e=b*log(a);
        if(e>maxExp){
            maxLine=i+1;
            maxExp=e;
        }
    }
    cout << maxLine;
}