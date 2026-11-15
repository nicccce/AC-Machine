#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> us(n+1),v(n+1,0),deep(n+1,0);
        for(int i=0;i<=n;i++)us[i]=i;
        function<int(int)> find=[&](int x){
            if(us[x]==x){
                return x;
            }
            int xx=us[x];
            find(xx);
            v[x]+=v[xx];
            deep[find(xx)]=max(deep[find(xx)],v[x]);
            return us[x]=find(xx);
        };
        auto comb=[&](int x,int y){
            int xx=find(x);
            deep[xx]=max(deep[xx],v[x]+1+deep[y]);
            v[y]=1;
            us[y]=x;
            find(y);
        };
        for(int i=0;i<n-1;i++){
            int a,b,c;
            cin>>a>>b>>c;
            comb(a,b);
            cout<<deep[c]<<' ';
        }cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
