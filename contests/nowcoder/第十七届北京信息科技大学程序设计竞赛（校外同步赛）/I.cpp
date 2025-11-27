// https://ac.nowcoder.com/acm/contest/122913/I
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin >> n;
        if(n%2){
            for(int i=0;i<n;i++)cout<<'a';
        }else{
            for(int i=0;i<n-1;i++)cout<<'a';
            cout<<'b';
        }
        cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
//aaaaabc
//aaaaaa
//aaaaaabc