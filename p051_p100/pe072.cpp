#include <math.h>
#include "../util/primes.h"

int N=1000000;

int main(){
    long long count=0;
    auto primes=Primes(sqrt(N));
    for(int n=2;n<=N;n++)
        count+=primes.totient(n);
    printf("%lld\n",count);
}