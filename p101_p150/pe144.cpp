#include <math.h>
#include <iostream>

int main(){
    int count=0;
    double xA=0,yA=10.1,xO=1.4,yO=-9.6;
    while(xO>0.01 || xO<-0.01 || yO<0){
        double slopeA   = (yO-yA)/(xO-xA);
        double slopeO   = -4*xO/yO;
        double tanA     = (slopeA-slopeO)/(1+slopeA*slopeO);
        double slopeB   = (slopeO-tanA)/(1+tanA*slopeO);
        double intceptB = yO-slopeB*xO;
        double a        = 4+slopeB*slopeB;
        double b        = 2*slopeB*intceptB;
        double c        = intceptB*intceptB-100;
        double ans1     = (-b+sqrt(b*b-4*a*c))/(2*a);
        double ans2     = (-b-sqrt(b*b-4*a*c))/(2*a);
        xA              = xO;
        yA              = yO;
        xO              = (abs(ans1-xO)>abs(ans2-xO))?ans1:ans2;
        yO              = slopeB*xO+intceptB;
        count++;
    }
    std::cout << count;
}