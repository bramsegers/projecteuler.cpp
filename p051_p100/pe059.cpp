#include <math.h>
#include "../util/strings.h"

int pw_length=3;
string look_for=" the ";

int main(){
    auto data=readFile("../files/pe059.txt");
    auto nums=strsplit(data[0],",");
    int text_length=nums.size();
    int cipher[text_length];
    for(int i=0;i<text_length;i++)
        cipher[i]=atoi(nums[i].c_str());

    int pw[pw_length];
    for(int i=0;i<pow(26,pw_length);i++){
        for(int j=0;j<pw_length;j++)
            pw[j]=97+((i/(int)pow(26,j))%26);

        int sum=0;
        string plain="";
        for(int c,j=0;j<text_length;j++){
            c=(pw[j%pw_length])^cipher[j];
            plain+=(char)c;
            sum+=c;
        }
        if(plain.find(look_for)!=string::npos){
            cout << plain << "\n" << sum << "\n";
        }
    }

}