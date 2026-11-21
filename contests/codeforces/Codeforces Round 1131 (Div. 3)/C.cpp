#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        int flag=0,sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];sum+=a[i];
            if(i!=1&&i!=n&&a[i]>=2)flag=1;
        }
        if(flag){
            cout<<sum-1<<'\n';
        }else{
            if(sum-(n-1)<2)cout<<-1<<'\n';
            else cout<<sum-n+1<<'\n';
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}