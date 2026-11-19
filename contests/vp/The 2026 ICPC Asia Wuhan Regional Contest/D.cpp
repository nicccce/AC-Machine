#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,m;
        cin>>n>>m;
        int s=0,cnt0=0;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)s=i,cnt0++;
        }
        vector<vector<int>> adj(n+1),adjans(n+1);
        for(int i=1;i<=n;i++){
            int k;cin>>k;
            while(k--){
                int x;
                cin>>x;
                adj[i].push_back(x);
            }
        }
        if(cnt0!=1){
            cout<<-1<<'\n';
            return;
        }
        vector<int> fa(n+1);
        for(int i=1;i<=n;i++){
            if(i==s)continue;
            int cnt=0;
            for(int x:adj[i]){
                if(a[x]==a[i]-1){
                    fa[i]=x;
                    cnt++;
                }
            }
            if(cnt!=1){
                cout<<-1<<'\n';
                return;
            }
            adjans[fa[i]].push_back(i);
        }
        stack<int> st;
        vector<bool> vis(n+1);
        vector<int> in(n+1),out(n+1),cur(n+1);
        int tot=0;
        st.push(s);
        vis[s]=1;
        in[s]=++tot;
        while(!st.empty()){
            int u=st.top();
            if(cur[u]<adjans[u].size()){
                int v=adjans[u][cur[u]++];
                vis[v]=1;
                in[v]=++tot;
                st.push(v);
            }else{
                out[u]=tot;
                st.pop();
            }
        }
        if(tot!=n){
            cout<<-1<<'\n';
            return;
        }
        for(int u=1;u<=n;u++){
            for(int v:adj[u]){
                if(!((in[u]<=in[v]&&out[v]<=out[u])||(in[v]<=in[u]&&out[u]<=out[v]))){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int x:adj[i]){
                if(fa[x]!=i)adjans[i].push_back(x);
            }
        }
        cout<<s<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=0;j<adjans[i].size();j++){
                cout<<adjans[i][j]<<(j+1==adjans[i].size()?'\n':' ');
            }
        }
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}