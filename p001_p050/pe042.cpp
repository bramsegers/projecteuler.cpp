#include "../util/strings.h"

int main(){
    int count=0;
    int tri[10000]={};
    for(int i=1;i<=100;i++) tri[i*(i+1)/2]=1;
    auto lines=readFile("../files/pe042.txt");
    auto line=replaceAll(lines[0],"\"","");
    auto words=strsplit(line,",");
    for(auto w:words){
        int score=0;
        for(auto c:w)
            score+=c-'A'+1;
        if(tri[score])
            cout << ++count << " " << w << " " << score << "\n";
    }
}