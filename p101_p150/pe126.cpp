#include <iostream>

int N=1000;

int main(){

    int M=20000;
    int* C=new int[M];
    auto cubes=[](int x,int y,int z,int n){
        return 2*(x*y+y*z+x*z)+4*(x+y+z+n-2)*(n-1);};

    for(int z=1;cubes(z,z,z,1)<M;z++)
        for(int y=z;cubes(z,y,z,1)<M;y++)
            for(int x=y;cubes(z,y,x,1)<M;x++)
                for(int n=1;cubes(z,y,x,n)<M;n++)
                    C[cubes(z,y,x,n)]++;
    
    int n=0;
    while(C[n]!=N) n++;
    std::cout << n;
}