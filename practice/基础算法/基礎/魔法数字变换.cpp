#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        int cnt=0;
        while (n!=1)
        {
            if(n%2==0) n/=2;
            else n=n*3+1;
            cnt++;
        }
        cout<<cnt;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}