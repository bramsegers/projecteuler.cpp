#include <stdio.h>

bool anagram(int n1,int n2){
    int a[10]={};
    int b[10]={};
    while(n1>0) {a[n1%10]++;n1/=10;}
    while(n2>0) {b[n2%10]++;n2/=10;}
    for(int i=0;i<10;i++)
        if(a[i]!=b[i]) return false;
    return true;
}

int main(){
    for(int i=1;;i++){
        if(!anagram(i,2*i)) continue;
        if(!anagram(i,3*i)) continue;
        if(!anagram(i,4*i)) continue;
        if(!anagram(i,5*i)) continue;
        if(!anagram(i,6*i)) continue;
        printf("%d\n",i);
        break;
    }       
}