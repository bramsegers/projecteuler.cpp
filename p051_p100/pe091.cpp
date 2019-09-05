#include <iostream>

int N=50;

int main(){
    int count=0;
    for(int x1=0;x1<=N;x1++)
        for(int y1=0;y1<=N;y1++)
            for(int x2=x1;x2<=N;x2++)
                for(int y2=0;y2<=y1;y2++)                
                    count+=(x1*(y2-y1)!=(x2-x1)*y1) // points not in 1 line?
                    && (x1*(x2-x1) == y1*(y1-y2)    // angle a,b = right?
                    ||  x2*(x2-x1) == y2*(y1-y2)    // angle b,c = right?
                    ||  x1*x2 == -y1*y2 );          // angle a,c = right?

    std::cout << count;
}