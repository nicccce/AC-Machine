#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i+3<=n;) {
            if(a[i]==a[i+1]&&a[i]==a[i+2]&&a[i]!=a[i+3]) {
                ans++;
                i+=4;
            }
            else if(a[i]==a[i+1]&&a[i]==a[i+3]&&a[i]!=a[i+2]) {
                ans++;
                i+=4;
            }
            else if(a[i]==a[i+2]&&a[i]==a[i+3]&&a[i]!=a[i+1]) {
                ans++;
                i+=4;
            }
            else if(a[i+1]==a[i+2]&&a[i+1]==a[i+3]&&a[i+1]!=a[i]) {
                ans++;
                i+=4;
            }
            else {
                i++;
            }
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}