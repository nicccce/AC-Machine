#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back({0,y});
            g[y].push_back({0,x});
        }
        vector<int>a(n),ivf(n+1);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ivf[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            for(auto &j:g[i]){
                j.first=ivf[j.second];
            }
            sort(g[i].begin(),g[i].end());
        }
        vector<int> aa;
        queue<int> que;
        vector<bool> vis(n+1);
        vis[1]=1;
        que.push(1);
        while (que.size())
        {
            int r=que.front();
            // cout<<r<<' ';
            vis[r]=1;
            aa.push_back(r);
            que.pop();
            for(auto j:g[r]){
                if(vis[j.second])continue;
                que.push(j.second);
            }
        }
        
        for(int i=0;i<n;i++){
            if(a[i]!=aa[i]){cout<<"No\n";return;}
        }
        cout<<"Yes\n";
    };
    solve();
    return 0;
}