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
        int n,k;
        cin>>n>>k;
        int cnt0=0,cnt1=0,cnt2=0;
        char op;
        for(int i=0;i<k;i++){
            cin>>op;
            cnt0+=(op=='0');
            cnt1+=(op=='1');
            cnt2+=(op=='2');
        }
        for(int i=0;i<n;i++){
            if(i<cnt0)cout<<'-';
            else if(i>=n-cnt1)cout<<'-';
            else if(i>=cnt0+cnt2&&i<n-cnt1-cnt2)cout<<'+';
            else if(n==k)cout<<'-';
            else cout<<'?';
        }
        cout<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}