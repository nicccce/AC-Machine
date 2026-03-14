// https://codeforces.com/problemset/problem/1949/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int mi=1000000000;
            for(int j=0;j<n;j++){
                mi=min(mi,abs(a[j]-b[(i+j)%n]));
            }
            ans=max(ans,mi);
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}