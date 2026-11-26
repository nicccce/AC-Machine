#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int> a(n+2,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        stack<pair<int,int>> st;
        vector<int> ls(n+2),rs(n+2);
        for(int i=0;i<=n+1;i++){
            while(!st.empty()&&st.top().first>a[i]){
                rs[st.top().second]=i;
                st.pop();
            }
            st.push({a[i],i});
        }st.pop();
        for(int i=n+1;i>=0;i--){
            while(!st.empty()&&st.top().first>a[i]){
                ls[st.top().second]=i;
                st.pop();
            }
            st.push({a[i],i});
        }st.pop();
        int ans=0;
        for(int i=1;i<=n;i++){
            int tmp=ans;
            ans+=1;
            if((a[i-1]>a[i]&&a[i+1]>a[i]))ans++;
            if(a[i-1]<a[i]){
                ans+=rs[i]-i-1;
            }if(a[i+1]<a[i]){
                ans+=i-ls[i]-1;
            }
            // cout<<ans-tmp<<' ';
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}