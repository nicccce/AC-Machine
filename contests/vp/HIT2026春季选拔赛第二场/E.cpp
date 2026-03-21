#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, bit[200005];
vector<int> pos[26];

void update(int i){
    for(;i<=n;i+=i&-i)bit[i]++;
}
int query(int i) {
    int s=0;
    for(;i>0;i-=i&-i) s+=bit[i];
    return s;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve=[&](){
        string s,ss;
        cin>>n>>s;
        ss=s;
        reverse(ss.begin(),ss.end());
        vector<stack<int>> id(256);
        for(int i=0;i<n;i++){
            id[s[i]].push(i+1);
        }
        vector<int> a(n+1);
        for(int i=n-1;i>=0;i--){
            a[i+1]=id[ss[i]].top();
            id[ss[i]].pop();
        }
        int ans=0;
        for(int i=n;i>=1;i--){
            ans+=query(a[i]-1);
            update(a[i]);
        }
        cout<<ans;
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}