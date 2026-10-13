#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> ans(n+1),vis(n+1);
    int aans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> a;
            queue<int> q;
            vis[i]=1;
            q.push(i);
            a.push_back(i);
            while(!q.empty()){
               int u=q.front();
               q.pop() ;
                for(auto [v,w]:g[u]){
                    if(vis[v]){
                        if((ans[v]^ans[u])!=w){
                            cout<<-1<<'\n';
                            return 0;
                        }
                    }else{
                        ans[v]=(ans[u]^w);
                        q.push(v);
                        vis[v]=1;
                        a.push_back(v);
                    }
                }
            }
            
            for(int b=0;b<=30;b++){
                int cnt=0;
                for(int i:a){
                    if((ans[i]&(1ll<<b))){
                        cnt++;
                    }
                }
                aans+=min(cnt,-cnt+(ll)a.size())*(1ll<<b);
            }
        }
    }
    cout<<aans<<'\n';
	return 0;
}