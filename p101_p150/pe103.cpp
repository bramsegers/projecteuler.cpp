#include <iostream>

int N=7;
int min;

bool valid(int * a,int n){
    for(int i=1;i<(1<<(n-1));i++){
        int b=0,j=(1<<(n-1))|i;
        for(int k=0;k<n;k++) b+=(j>>k)&1;
        for(int c=1;c<(1<<b)-1;c++){
            int p=0,s=0;
            for(int e=0,d=0;d<n;d++){
                if(!((j>>d)&1)) continue;
                p+=(c>>e)&1?-1:1;
                s+=(c>>e)&1?-a[d]:a[d];
                e++;
            }
            if(s==0||(p>0 && s<=0)) return false;
        }
    }
    return true;
}

void dp(int * a,int n,int m,int i,int s){
    if(i==n){
        min=s;
        for(int i=0;i<n;i++) std::cout<<a[i];
        std::cout<<" "<<min<<"\n";
    }
    for(int k=m;k<=(1<<n) && s+k<min;k++){
        a[i]=k;
        if(valid(a,i+1)) dp(a,n,k+1,i+1,s+k);
    }
}

int main(){
    for(int n=1;n<=N;n++){
        min=1<<30;
        std::cout << n << "\n";
        dp(new int[n],n,1,0,0);
    }
}