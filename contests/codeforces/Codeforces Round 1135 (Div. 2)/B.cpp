#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
       int n,k;cin>>n>>k;
       string s;cin>>s;
       int cnt1,cnt0=0;
       for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cnt0++;
        }
       }cnt1=n-cnt0;
       int m=min(n,max(cnt1,cnt0)+k);
       cout<<1+(m+1)*m/2+(n-m+1)*(n-m)/2<<"\n";
       
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
