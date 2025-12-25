#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,k,dp0=0;
        cin>>n>>k;
        if(k&1){
            for(int i=0;i<k;i++)cout<<n<<' ';
            cout<<"\n";return;
        }
        vector<int>a(k);
        for(int i=30;i>=0;i--){
            if((n>>i)&1){
                for(int j=0;j<k;j++)a[j]+=(1<<i)*(j!=min(dp0,k-1));
                if(dp0<k)dp0++;
            }else for(int j=0;j<dp0-(dp0&1);j++)a[j]+=(1<<i);
        }for(int i=0;i<k;i++)cout<<a[i]<<' ';
        cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}