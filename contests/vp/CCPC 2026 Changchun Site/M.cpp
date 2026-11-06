#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
std::vector<int> primes;
bool is_prime[N];
int d[N];
int c[N];

void sieve(int n) {
    std::fill(is_prime + 2, is_prime + n + 1, true);
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            d[i] = 2;
            c[i] = 1;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) {
                c[i * p] = c[i] + 1;
                d[i * p] = d[i] / (c[i] + 1) * (c[i * p] + 1);
                break;
            }
            c[i * p] = 1;
            d[i * p] = d[i] * 2;
        }
    }
}
signed main(){
    auto solve=[&](){
        int m,n,ans=0;
        cin>>n>>m;
        sieve(m);
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            int cha=-1;
            for(int j=1;i+j<n&&i-j>=0;j++){
                if(a[i+j]-a[i-j]!=0){
                    if(cha==-1)cha=abs(a[i+j]-a[i-j]);
                    cha=__gcd(cha,abs(a[i+j]-a[i-j]));
                }
                ans+=(cha==-1?m-1:d[cha]-1);
            }
        }
        for(int i=1;i<n;i++){
            int cha=-1;
            for(int j=1;i+j-1<n&&i-j>=0;j++){
                if(a[i+j-1]-a[i-j]!=0){
                    if(cha==-1)cha=abs(a[i+j-1]-a[i-j]);
                    cha=__gcd(cha,abs(a[i+j-1]-a[i-j]));
                }
                ans+=(cha==-1?m-1:d[cha]-1);
            }
        }
        cout<<ans<<'\n';
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
}