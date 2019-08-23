#include <vector>

class Primes{

    private:

        long long N;
        std::vector<int> sieve;

    public:

        struct factor {long long prime; int exp;};
        std::vector<long long> vec;

        Primes(long long n){
            N=n;
            sieve=std::vector<int>((n>>6)+1);
            for(long long i=3;i*i<=n;i+=2)
                if((sieve[i>>6]&(1<<((i>>1)&31)))==0)
                    for(long long k,j=i;(k=i*j)<=n;j+=2)
                        sieve[k>>6]|=1<<((k>>1)&31);
            vec.push_back(2);
            for(long long i=3;i<=n;i+=2)
                if((sieve[i>>6]&(1<<((i>>1)&31)))==0)
                    vec.push_back(i);
        }

        std::vector<factor> factors(long long n){
            if(n>N*N) throw "prime out of range";
            int e;
            std::vector<factor> f;
            for(long long p:vec){
                if(n==1 || p*p>n) break;
                for(e=0;n%p==0;e++) n/=p;
                if(e>0) f.push_back({p,e});
            }
            if(n>1) f.push_back({n,1});
            return f;
        }

        bool get(long long n){
            if(n<2) return false;
            if(n==2) return true;
            if((n&1)==0) return false;
            if(n<=N) return ((sieve[n>>6]&(1<<((n>>1)&31)))==0);
            if(n>N*N) throw "prime out of range";
            for(long long p:vec){
                if(p*p>n) return true;
                if(n%p==0) return false;
            }
            return true;
        }

        long long totient(long long n){
            if(n>N*N) throw "prime out of range";
            long long e,t=n;
            for(long long p:vec){
                if(n==1 || p*p>n) break;
                for(e=0;n%p==0;e++) n/=p;
                if(e>0) t-=t/p;    
            }
            if(n>1) t-=t/n;
            return t;
        }

};