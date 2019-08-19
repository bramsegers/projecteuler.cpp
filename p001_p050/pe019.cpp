#include <stdio.h>

int dayNumber(int y,int m,int d){
    static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    y-=m<3;
    return (y+y/4-y/100+y/400+t[m-1]+d)%7;
}

int main(){
    int count=0;
    for(int y=1901;y<=2000;y++)
        for(int m=1;m<=12;m++)
            if(dayNumber(y,m,1)==0){
                printf("%d.%02d.01\n",y,m);
                count++;
            }
    printf("%d\n",count);
}