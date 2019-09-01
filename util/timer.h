#include <chrono>
#include <stdio.h>

void timer(){
    static long long last=-1;
    auto ms=std::chrono::
        duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch())
        .count();
    if(last<0) last=ms;
    else{
        printf("%lldms\n",ms-last);
        last=-1;
    }
}