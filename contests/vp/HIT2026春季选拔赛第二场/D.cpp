#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve=[&](){
        int n_exp,q;
        cin>>n_exp>>q;
        int n=1<<n_exp;
        vector<int> a(2*n);
        for(int i=0;i<n;i++)cin>>a[n+i];
        for(int i=n-1;i>0;i--)a[i]=a[2*i]^a[2*i+1];
        while(q--){
            int b,c;
            cin>>b>>c;
            int cur=n+b-1,val=c,ans=0;
            for(int i=0;i<n_exp;i++){
                int sib=cur^1;
                int s_val=a[sib];
                int sz=1LL<<i;
                if(cur%2==0){
                    if(s_val>val)ans+=sz;
                }else{
                    if(s_val>=val)ans+=sz;
                }
                val^=s_val;
                cur>>=1;
            }
            cout<<ans<<"\n";
        }
    };
    int t;
    for(cin>>t;t;t--)solve();
    return 0;
}