#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<vector<int>> gra(n+1,vector<int>());
        vector<int> indeg(n+1);
        int u,v,x,y;
        for(int i=1;i<n;i++){
            cin>>u>>v>>x>>y;
            if(u>v)swap(v,u);
            if(x<=y)gra[u].push_back(v),indeg[v]++;
            else gra[v].push_back(u),indeg[u]++;
        }
        stack<int> st;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0)st.push(i);
        }
        vector<int> ans(n+1);
        int k=1;
        while (st.size())
        {
            u=st.top();st.pop();
            ans[u]=k++;
            for(auto i:gra[u]){
                indeg[i]--;
                if(indeg[i]==0)st.push(i);
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
        cout<<'\n';
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}