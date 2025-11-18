// https://codeforces.com/contest/2160/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>> n;
        int l=0;
        int tmp=n;
        while(tmp!=0){
            l++;tmp>>=1;
        }
        int ll=0,rr=0;
        if(n==0){
            cout<<"YES\n";
            return;
        }
        for(int i=0;i<l;i++){
            ll+=(n&(1ll<<i));
            for(int j=l;j<=2*l;j++){
                if((n&(1ll<<i))==0){rr=0;
                for(int k=i;k<j;k++){
                    rr<<=1;
                    rr+=((n&(1ll<<k))>>k);
                }
                if(rr==ll){
                    // cout<<i<<j<<'\n';
                    cout<<"YES\n";
                    return;
                }}
                rr=0;
                for(int k=i+1;k<j;k++){
                    rr<<=1;
                    rr+=((n&(1ll<<k))>>k);
                }
                if(rr==ll){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}