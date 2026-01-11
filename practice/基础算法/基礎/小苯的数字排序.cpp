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
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]%2==0) a[i]-=1e9;
        }
        sort(a.begin()+1,a.end());
        for(int i=1;i<=n;i++) {
            if(a[i]<0) a[i]+=1e9;
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}