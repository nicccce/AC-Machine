#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        
        auto check=[&](int l,int r){
            cout<<"? "<<l<<" "<<r<<endl;
            int ans;cin>>ans;
            return ans;
        };
        int l=1,r=n,mid,ans=-1;
        while (l<=r)
        {
            mid=(l+r)/2;
            int tmp=check(mid,n);
            if(tmp!=n-mid+1){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        if(ans==-1||ans==n){
            cout<<"! NO"<<endl;
        }else{
            cout<<"! YES"<<endl;
        }
        
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}