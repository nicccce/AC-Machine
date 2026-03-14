// https://codeforces.com/problemset/problem/1277/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            int cnt=0;
            while (x%2==0)
            {
                x=x/2;
                cnt++;
            }
            mp[x]=max(mp[x],cnt);
        }
        int ans=0;
        for(auto [k,v]:mp){
            ans+=v;
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}