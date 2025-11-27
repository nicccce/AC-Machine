// https://ac.nowcoder.com/acm/contest/122913/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        if(n==2||n==3||n==4)
            cout<<"-1\n";
        else{
            cout<<3+(n-3)*2-1<<"\n1 2\n1 3\n3 2\n";
            for(int i=4;i<=n;i++)
                cout<<"1 "<<i<<"\n";
            for(int i=5;i<=n;i++)
                cout<<i-1<<" "<<i<<"\n";
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}