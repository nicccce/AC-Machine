// https://codeforces.com/contest/2151/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
int fac[N+5]={1},inv[N+5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto qpow=[&](int b,int p) {
            int r=1;
            while(p) {
                if(p&1) r=r*b%mod;
                b=b*b%mod,p>>=1;
            }
            return r;
        };
    for(int i=1; i<=N; i++) fac[i]=fac[i-1]*i%mod;
	inv[N]=qpow(fac[N],mod-2);
	for(int i=N-1; i>=0; i--) inv[i]=inv[i+1]*(i+1)%mod;
    auto solve = [&]() {
        int n;
		cin>>n;
		int p=(n/2)+(n&1),s=0,ans=1;
        vector<int> a(n+1);
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=n; i>p; i--)
			if(a[i]!=0) {
				cout<<0<<'\n';
                return;
			}
		if(n&1) {
			if(a[p]>1) {
				cout<<0<<'\n';
				return;
			} else if(a[p]==0)s++;
			p--;
		}
		for(int i=p; i>=1; i--) {
			s+=2;
			if(s<a[i]) {
				cout<<0<<'\n';
				return;
			}
			ans=ans*fac[s]%mod*inv[a[i]]%mod*inv[s-a[i]]%mod;
			s-=a[i];
		}
		if(s) cout<<0<<'\n'; 
		else cout<<ans<<'\n';
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}