#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto solve=[&](){
        int n,m;
        cin>>n>>m;
        vector<string> g(n);
        for(auto &s:g)cin>>s;
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        int N=(n+1)*(m+1);
        auto id=[&](int x,int y){
            return x*(m+1)+y;
        };
        auto border=[&](int u){
            int x=u/(m+1),y=u%(m+1);
            return x==0||x==n||y==0||y==m;
        };
        int s=id(sx,sy),t=id(ex,ey);
        vector<array<int,4>> adj(N);
        vector<vector<int>> e(N),chain(N);
        vector<int> mate(N,-1);
        for(int x=0;x<=n;x++){
            for(int y=0;y<=m;y++){
                for(int d=0;d<4;d++){
                    int nx=x+dx[d],ny=y+dy[d];
                    adj[id(x,y)][d]=(nx>=0&&nx<=n&&ny>=0&&ny<=m)?id(nx,ny):-1;
                }
            }
        }
        auto add=[&](int u,int v){
            e[u].push_back(v);
            e[v].push_back(u);
        };
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i-1][j]!=g[i][j])add(id(i,j),id(i,j+1));
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(g[i][j-1]!=g[i][j])add(id(i,j),id(i+1,j));
            }
        }
        for(int u=0;u<N;u++){
            if(e[u].size()>2){
                cout<<"NO\n";
                return;
            }
        }
        vector<bool> vis(N);
        for(int u=0;u<N;u++){
            if(e[u].size()!=1||vis[u])continue;
            vector<int> p;
            int pre=-1,cur=u;
            while(cur!=-1){
                p.push_back(cur);
                vis[cur]=1;
                int nxt=-1;
                for(int v:e[cur]){
                    if(v!=pre)nxt=v;
                }
                pre=cur;
                cur=nxt;
            }
            int v=p.back();
            mate[u]=v;
            mate[v]=u;
            chain[u]=p;
            reverse(p.begin(),p.end());
            chain[v]=p;
        }
        for(int u=0;u<N;u++){
            if(!e[u].empty()&&!vis[u]){
                cout<<"NO\n";
                return;
            }
        }
        vector<int> ring,a,b;
        for(int j=0;j<m;j++)ring.push_back(id(0,j));
        for(int i=0;i<n;i++)ring.push_back(id(i,m));
        for(int j=m;j>0;j--)ring.push_back(id(n,j));
        for(int i=n;i>0;i--)ring.push_back(id(i,0));
        int k=find(ring.begin(),ring.end(),s)-ring.begin();
        int len=ring.size();
        for(int i=0;;i++){
            int u=ring[(k+i)%len];
            a.push_back(u);
            if(u==t)break;
        }
        b.push_back(s);
        for(int i=1;;i++){
            int u=ring[(k-i+len)%len];
            if(u==t)break;
            b.push_back(u);
        }
        int A=a.size(),B=b.size();
        vector<int> side(N,-1),pos(N,-1);
        for(int i=0;i<A;i++)side[a[i]]=0,pos[a[i]]=i;
        for(int j=1;j<B;j++)side[b[j]]=1,pos[b[j]]=j;
        struct Node{
            vector<int> p;
            int cnt=-1;
        };
        vector<array<Node,2>> dp(A*B);
        dp[0][0].p=dp[0][1].p={s};
        auto inside=[&](int u,int i,int j){
            return side[u]==0?pos[u]<=i:pos[u]<=j;
        };
        auto upd=[&](int i,int j,int d,const Node &cur,const vector<int> &p){
            vector<bool> used(N);
            for(int u:cur.p)used[u]=1;
            for(int u:p)used[u]=1;
            vector<int> q(N);
            int l=0,r=0;
            if(!used[t]){
                used[t]=1;
                q[r++]=t;
                while(l<r){
                    int u=q[l++];
                    for(int v:adj[u]){
                        if(v!=-1&&!used[v]){
                            used[v]=1;
                            q[r++]=v;
                        }
                    }
                }
            }
            auto &to=dp[i*B+j][d];
            if(!to.p.empty()&&to.cnt>=r)return;
            to.p=cur.p;
            to.p.insert(to.p.end(),p.begin(),p.end());
            to.cnt=r;
        };
        auto connect=[&](const Node &cur,int dest,int d){
            vector<bool> used(N);
            for(int u=0;u<N;u++)used[u]=border(u)||!e[u].empty();
            for(int u:cur.p)used[u]=1;
            used[dest]=0;
            vector<int> p;
            function<bool(int,int)> dfs=[&](int u,int dir){
                if(u==dest){
                    p.push_back(u);
                    return true;
                }
                for(int i=0;i<4;i++){
                    int nd=(dir+(d==0?3+i:5-i))%4;
                    int v=adj[u][nd];
                    if(v==-1||used[v])continue;
                    used[v]=1;
                    if(dfs(v,nd)){
                        p.push_back(u);
                        return true;
                    }
                }
                return false;
            };
            int u=cur.p.back(),dir=0;
            for(int i=0;i<4;i++){
                if(adj[u][(i+2)%4]==-1){
                    dir=i;
                    break;
                }
            }
            if(dfs(u,dir)){
                reverse(p.begin(),p.end());
                p.erase(p.begin());
            }
            return p;
        };
        for(int sum=0;sum<=A+B-2;sum++){
            for(int i=max(0LL,sum-B+1);i<A&&i<=sum;i++){
                int j=sum-i;
                for(int d=0;d<2;d++){
                    Node cur=dp[i*B+j][d];
                    if(cur.p.empty())continue;
                    int u=cur.p.back();
                    if(d==0&&j+1<B&&e[b[j+1]].empty()){
                        upd(i,j+1,0,cur,{});
                    }
                    if(d==1&&i+1<A&&a[i+1]!=t&&e[a[i+1]].empty()){
                        upd(i+1,j,1,cur,{});
                    }
                    if(u==t)continue;
                    if(mate[u]!=-1&&!inside(mate[u],i,j)){
                        int v=mate[u],ni=i,nj=j;
                        bool ok=1;
                        if(side[v]==0){
                            for(int z=i+1;z<pos[v];z++){
                                if(!e[a[z]].empty())ok=0;
                            }
                            ni=pos[v];
                        }else{
                            for(int z=j+1;z<pos[v];z++){
                                if(!e[b[z]].empty())ok=0;
                            }
                            nj=pos[v];
                        }
                        if(ok){
                            vector<int> p(chain[u].begin()+1,chain[u].end());
                            upd(ni,nj,side[v],cur,p);
                        }
                        continue;
                    }
                    for(int h=0;h<2;h++){
                        int ni=i+(h==0),nj=j+(h==1);
                        if(ni>=A||nj>=B)continue;
                        int v=h==0?a[ni]:b[nj];
                        if(mate[v]!=-1&&inside(mate[v],i,j))continue;
                        vector<int> p;
                        if(h==d)p={v};
                        else p=connect(cur,v,h);
                        if(!p.empty())upd(ni,nj,h,cur,p);
                    }
                }
            }
        }
        auto &ans=dp[A*B-1][0].p;
        if(ans.empty()){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n"<<ans.size()<<'\n';
        for(int u:ans)cout<<u/(m+1)<<' '<<u%(m+1)<<'\n';
    };
    solve();
}