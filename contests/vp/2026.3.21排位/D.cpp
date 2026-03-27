#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    auto solve=[&](){
        int h,c,t;
        cin>>h>>c>>t;
        // (h-c)>=(4x+2)t - (2x+1)(h+c)
        // h-c + h+c-2t>=(4t-2(h+c))x
        // (h-c)
        //
        // x<=....
        if(t==h){
            cout<<1<<'\n';
            return;
        }
        int zj=floor(1.0*(2*h-2*t)/(4*t-2*(h+c)));
        int finzj=2;
        long double finans=abs(0.5*(h+c)-t);
        for(int i=max(0ll,zj-3);i<=zj+3;i++){
            double ans=abs(1.0*(i*(h+c)+h)/(2*i+1)-t);
            // cout<<i<<' '<<ans<<'\n';
            if(abs(ans-finans)<0.000000001){
                finzj=min(finzj,i*2+1);
            }else if(ans<finans){
                finans=ans;
                finzj=2*i+1;
            }
        }
        stack<char> st;
        st=stack<char>();
        cout<<finzj<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}