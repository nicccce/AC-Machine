#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,q;
        cin>>n>>q;
        string s;cin>>s;
        s.insert(s.begin(),'0');
        vector<int> cnt0prefix(n+1),cnt1prefix(n+1),cprefix(n+1);
        for(int i=1;i<=n;i++){
            cnt0prefix[i]=cnt0prefix[i-1]+(s[i]=='0');
            cnt1prefix[i]=cnt1prefix[i-1]+(s[i]=='1');
            cprefix[i]=cprefix[i-1]+(i>1&&s[i]!=s[i-1]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int cnt0=cnt0prefix[r]-cnt0prefix[l-1],cnt1=cnt1prefix[r]-cnt1prefix[l-1],c=(cprefix[r]-cprefix[l]+(s[l]!=s[r]))/2;
            // cout<<cnt0<<cnt1<<c<<'\n';
            int k=max({(cnt0+1)/2,(cnt1+1)/2,c,(cnt0+cnt1-c+2)/3});
            cout<<4*k-cnt0-cnt1<<'\n';
        }
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}