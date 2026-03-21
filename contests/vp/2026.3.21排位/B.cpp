#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n,d;
        cin>>n>>d;
        vector<pair<int,int>> ms(n+1);
        for(int i=1;i<=n;i++)cin>>ms[i].first>>ms[i].second;
        sort(ms.begin()+1,ms.end());
        vector<int> prefix(n+1);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+ms[i].second;
        }
        int l=1,r=1;
        int ans=0;
        while (l<=n)
        {
            while (r<=n&&ms[r].first<ms[l].first+d)
            {
                r++;
            }
            ans=max(ans,prefix[r-1]-prefix[l-1]);
            l++;
        }
        cout<<ans<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}