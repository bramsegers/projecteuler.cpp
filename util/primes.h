#include <iostream>
#include <vector>
#include <chrono>

class Primes{

    private:
        long long N;
        std::vector<int> s;
        bool get2(long long i){
            for(auto p:pr){
                if(p*p>i) return true;
                if(i%p==0) return false;
            }
            return true;
        }
        long long now(){
            return std::chrono::
            duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch())
            .count();
        }
   
    public:
        struct factor {long long prime; int exp;};
        std::vector<long long> pr;
        Primes(long long n, bool log=false){
            if(log) std::cout << "sieving primes up to " << n << " ...\n";
            long long ms=now();
            N=n;      
            s=std::vector<int>((n>>6)+1);            
            for(long long i=3;i*i<=n;i+=2){
                if((s[i>>6]&(1<<((i>>1)&31)))==0){
                    for(long long k,j=i;(k=i*j)<=n;j+=2){
                        s[k>>6]|=1<<((k>>1)&31);
                    }
                }
            }
            pr.push_back(2);
            for(long long i=3;i<=n;i+=2)
                if((s[i>>6]&(1<<((i>>1)&31)))==0)
                    pr.push_back(i);
            ms=now()-ms;
            if(log) std::cout << "primes found: " << pr.size() << "\n";
            if(log) std::cout << "time elapsed: " << ms << "ms\n";
        }
        std::vector<factor> factors(long long n){
            int e;
            std::vector<factor> f;
            for(long long p:pr){
                if(n==1 || p*p>n) break;
                for(e=0;n%p==0;e++) n/=p;
                if(e>0) f.push_back({p,e});
            }
            if(n>1) f.push_back({n,1});
            return f;
        }
        bool get(long long i){
            if(i<2) return false;
            if(i==2) return true;
            if((i&1)==0) return false;
            if(i>N*N) throw "prime out of range";
            if(i>N) return get2(i);
            return ((s[i>>6]&(1<<((i>>1)&31)))==0);
        }

};