#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    auto solve=[&](){
        int n;cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> p(n+1);
        for(int i=1;i<=n;i++)cin>>p[i];
        
        vector<int> dep(n+1,0);
        vector<vector<int>> up(n+1,vector<int>(20,0));
        auto dfs=[&](auto&& dfs,int u,int fa)->void{
            up[u][0]=fa;
            for(int i=1;i<20;i++)up[u][i]=up[up[u][i-1]][i-1];
            for(int v:adj[u])if(v!=fa){
                dep[v]=dep[u]+1;
                dfs(dfs,v,u);
            }
        };
        dfs(dfs,1,0);
        
        auto get_lca=[&](int u,int v){
            if(dep[u]<dep[v])swap(u,v);
            for(int i=19;i>=0;i--)if(dep[u]-(1<<i)>=dep[v])u=up[u][i];
            if(u==v)return u;
            for(int i=19;i>=0;i--)if(up[u][i]!=up[v][i])u=up[u][i],v=up[v][i];
            return up[u][0];
        };
        auto dis=[&](int u,int v){
            return dep[u]+dep[v]-2*dep[get_lca(u,v)];
        };
        
        int u=p[1],v=p[1],ans=1;
        for(int i=2;i<=n;i++){
            int x=p[i];
            if(dis(u,x)+dis(x,v)==dis(u,v)){
            }else if(dis(u,v)+dis(v,x)==dis(u,x)){
                v=x;
            }else if(dis(v,u)+dis(u,x)==dis(v,x)){
                u=x;
            }else break;
            ans=i;
        }
        cout<<ans<<"\n";
    };
    int t;cin>>t;
    while(t--)solve();
    return 0;
}