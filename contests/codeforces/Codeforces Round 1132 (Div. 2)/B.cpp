#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,k;cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        int mx=0,sum=0;
        for(int i=0;i<n;i++){
            if(i==0||a[i]*i>=sum)mx++;
            sum+=a[i];
        }
        vector<int>d=a;
        reverse(d.begin(),d.end());
        int min_cnt=0;
        sum=0;
        for(int i=0;i<n;i++){
            if(i==0||d[i]*i>=sum)min_cnt++;
            sum+=d[i];
        }
        if(k<min_cnt||k>mx){
            cout<<"NO\n";
            return;
        }
        cout<<"Yes\n";
        vector<int>ans;
        for(int i=n-k;i<n;i++)
            ans.push_back(a[i]);
        for(int i=n-k-1;i>=0;i--)
            ans.push_back(a[i]);
        for(int i=0;i<n;i++)cout<<ans[i]<<' ';
        cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}