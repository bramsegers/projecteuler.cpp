long long gcd(long long m,long long n){
    return n==0?m:gcd(n,m%n);
}