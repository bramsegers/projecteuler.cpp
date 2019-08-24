#include <vector>
#include <stdio.h>

int M=1000000;

int main(){
    std::vector<int> p={1};
    int n=0,q=1;
    while(q!=0){
        n++;
        q=0;
        int t=0,k=1,m=1,g;
        for(g=1;g<=n;g=(3*k*k-k)/2){
            q+=m*p[n-g];
            q%=M;
            k=-k;
            if(++t==2){
                t=0;
                k++;
                m=-m;
            }
        }
        p.push_back(q);
    }
    printf("%d\n",n);
}