#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(x<=y)x+=(1<<a[i]);
            else y+=(1<<a[i]);
        }
        cout<<x*y<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}