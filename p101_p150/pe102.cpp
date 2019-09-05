#include "../util/strings.h"

struct point{int x; int y;};

bool insidePoly(point& p,point* poly,int v){
    bool inside=false;
    for(int i=0,j=v-1;i<v;j=i++){
        int xi=poly[i].x,yi=poly[i].y;
        int xj=poly[j].x,yj=poly[j].y;
        bool intersect=((yi>p.y)!=(yj>p.y))
            && (p.x<(double)(xj-xi)*(p.y-yi)/(yj-yi)+xi);
        if(intersect) inside=!inside;
    }
    return inside;
}

int main(){
    int count=0;
    point origin={0,0};
    for(auto t:readFile("../files/pe102.txt")){
        auto r=strsplit(t,",");
        point poly[]={
            {stoi(r[0]),stoi(r[1])},
            {stoi(r[2]),stoi(r[3])},
            {stoi(r[4]),stoi(r[5])}
        };
        if(insidePoly(origin,poly,3)) count++;
    }
    cout << count;
}