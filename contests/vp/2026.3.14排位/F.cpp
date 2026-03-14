// https://codeforces.com/problemset/problem/859/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        vector<int> a(n+1),dp(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }int summ=a[n];
        dp[n]=a[n];
        for(int i=n-1;i>=1;i--){
            dp[i]=max((summ-dp[i+1])+a[i],dp[i+1]);
            summ+=a[i];
        }
        cout<<summ-dp[1]<<' '<<dp[1]<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}