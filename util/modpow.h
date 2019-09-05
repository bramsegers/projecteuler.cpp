long long modpow(long long b,long long e,long long m){
    b%=m;
    long long p;
    for(p=1;e>0;e>>=1){
        if(e&1) p=(p*b)%m;
        b=(b*b)%m;
    }
    return p;
}