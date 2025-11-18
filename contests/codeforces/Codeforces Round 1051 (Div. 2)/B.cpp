// https://codeforces.com/contest/2143/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,k,ans=0;
        cin>>n>>k;
        vector<int> a(n),b(k);
        for(int i=0;i<n;i++)cin>>a[i],ans+=a[i];
        for(int i=0;i<k;i++)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ai=n,bi=0;
        while (bi<k)
        {
            ai-=b[bi++];
            if(ai<0)break;
            ans-=a[ai];
        }
        cout<<ans<<'\n';
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}