#include <iostream>
#include <algorithm>
#include "../util/strings.h"

int main(){
    auto lines=readFile("../files/pe022.txt");
    auto line=replaceAll(lines[0],"\"","");
    auto names=strsplit(line,",");
    sort(names.begin(),names.end());
    int score,i=0,sum=0;
    for(auto n:names){
        i++;
        score=0;
        for(auto c:n)
            score+=c-'A'+1;
        sum+=i*score;
    }
    cout << sum;
}