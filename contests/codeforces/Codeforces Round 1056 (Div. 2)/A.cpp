// https://codeforces.com/contest/2152/problem/A
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
        cin>>n;
        int sz=n,bz=0,cnt=0;
        while(sz!=1||bz!=1){
            cnt+=(bz)/2;
            bz=(bz+1)/2;
            bz+=sz/2;
            cnt+=sz/2;
            sz=(sz+1)/2;
        }
        cout<<cnt+1<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}