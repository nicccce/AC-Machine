#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,k;cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        auto check=[&](int x){
            int y=(x-1)/(n-1)-1,rem=(x-1)%(n-1);
            vector<int>tmpa(a);
            int sum=0,need=0;
            for(int i=0;i<n;i++){
                tmpa[i]-=y+1;
                if(n-i<=rem){
                    tmpa[i]--;
                }
                if(tmpa[i]<0){
                    sum+=-tmpa[i];
                    need+=max(0ll,(-tmpa[i]-(y+1)/2));
                }
            }
            if(sum>(y)+k){
                return false;
            }
            if(k<need){
                return false;
            }
            return true;
        };
        // for(int i=1;i<=30;i++){
        //     cout<<check(i)<<' ';
        // }cout<<'\n';
        int l=n+1,r=1e18,mid,ans=n;
        while(l<=r){
            mid=l+((r-l)>>1);
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}