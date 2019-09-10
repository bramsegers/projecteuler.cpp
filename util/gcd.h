long long gcd(long long m,long long n){
    return n==0?m:gcd(n,m%n);
}

long long lcm(long long a,long long b){
    return a*(b/gcd(a,b));
}