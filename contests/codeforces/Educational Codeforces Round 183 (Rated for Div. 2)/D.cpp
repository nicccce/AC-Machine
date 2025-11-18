// https://codeforces.com/contest/2152/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    vector<vector<vector<int>>> dp(31,vector<vector<int>>(15*29+1,vector<int>(0)));
    for(int i=1;i<=30;i++){
        dp[i][0].push_back(i);
        for(int j=1;j<i;j++){
            for(int k=0;k<=j*(j-1)/2;k++){
                auto x=dp[j][k];
                if(x.size()==0)continue;
                if(dp[i][k+(i-j)*j].size()!=0)continue;
                dp[i][k+(i-j)*j]=x;
                dp[i][k+(i-j)*j].push_back(i);
            }
        }
    }
    auto solve = [&]() {
        int n,k;
        cin>>n>>k;
        int tt=0;
        if(dp[n][k].size()==0){cout<<0<<'\n';return;}
        for(auto i:dp[n][k]){
            for(int j=n+1-i;j<=n-tt;j++)cout<<j<<' ';
            tt=i;
        }
        cout<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}