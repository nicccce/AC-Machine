// https://codeforces.com/gym/105632/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        
        int c1=__gcd(a,x),c2=__gcd(b,y);
        if((c1!=0&&(a/c1&(a/c1-1)))||(c2!=0&&(b/c2&(b/c2-1)))){
            cout<<-1;return;
        }
        vector<array<int,4>>ans;
        while((x<a&&x>0)||(y<b&&y>0)){
            int xx=(2*x<a)?0:a,yy=(2*y<b)?0:b;
            x=2*x-xx,y=2*y-yy;
            ans.push_back({x,y,xx,yy});
        }
        int aaaaaaaaaaaaaaaaaaaaaaaaaa=ans.size();
        cout<<ans.size()<<'\n';
        for(int i=aaaaaaaaaaaaaaaaaaaaaaaaaa-1;i>=0;i--)cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<' '<<ans[i][3]<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}