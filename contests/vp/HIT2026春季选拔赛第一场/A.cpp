#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> b(n),a(2*n),mp(2*n+1,0);
        for(int i=0;i<n;i++){
            cin>>b[i];
            a[i*2]=b[i];
            mp[b[i]]=1;
        }
        for(int i=0;i<n;i++){
            int zhizheng=b[i]+1;
            while(mp[zhizheng]){
                zhizheng++;
                if(zhizheng>2*n){
                    cout<<"-1\n";
                    return;
                }
            }
            a[i*2+1]=zhizheng,mp[zhizheng]=1;
        }
        for(int i=0;i<n*2;i++){
            cout<<a[i]<<' ';
        }cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
