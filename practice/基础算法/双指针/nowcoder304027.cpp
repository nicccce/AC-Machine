// https://ac.nowcoder.com/acm/problem/304027
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if((a-c)*(b-d)<0)cout<<"A\n";
        else if(a-d>0||c-b>0)cout<<"B\n";
        else cout<<"C\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}