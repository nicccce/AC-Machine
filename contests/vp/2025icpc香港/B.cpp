#include<bits/stdc++.h>
#define N 2017
#define ll long long
using namespace std;

struct node{
    int v;ll w;
    node(int _v = 0,ll _w = 0){
        v = _v,w = _w;
    }
};

vector<node>to[N];

int n,siz[N];ll tmpf[2*N],tmpg[2*N],tmph[2*N],f[N][2*N],g[N][2*N],h[N][2*N];

void dfs(int u,int fa){
    siz[u] = 1;
    for(int i = 0;i < to[u].size();i += 1){
        int v = to[u][i].v;ll w = to[u][i].w;
        if(v == fa)continue;
        dfs(v,u);
        for(int j = 0;j <= 2*(siz[u]+siz[v]-1);j += 1)tmpf[j] = f[u][j],tmpg[j] = g[u][j],tmph[j] = h[u][j];
        for(int j = 2*(siz[u]-1);j >= 0;j -= 1){
            for(int k = 2*(siz[v]-1);k >= 0;k -= 1){
                tmpf[j+k+1] = max(tmpf[j+k+1],g[u][j]+g[v][k]+w);
                tmpg[j+k+1] = max(tmpg[j+k+1],h[u][j]+g[v][k]+w);
            }
            tmpf[j+2*(siz[v]-1)+2] = max(tmpf[j+2*(siz[v]-1)+2],f[u][j]+h[v][2*(siz[v]-1)]+2ll*w);
            tmpg[j+2*(siz[v]-1)+2] = max(tmpg[j+2*(siz[v]-1)+2],g[u][j]+h[v][2*(siz[v]-1)]+2ll*w);
            tmph[j+2*(siz[v]-1)+2] = max(tmph[j+2*(siz[v]-1)+2],h[u][j]+h[v][2*(siz[v]-1)]+2ll*w);
        }
        for(int j = 0;j <= 2*(siz[u]+siz[v]-1);j += 1)f[u][j] = max(tmpf[j],max(tmpg[j],tmph[j])),g[u][j] = tmpg[j],h[u][j] = tmph[j];
        siz[u] += siz[v];
    }
}

void solve(){
    cin >> n;
    ll ans = 0;
    for(int i = 1;i < n;i += 1){
        int u,v,w;cin >> u >> v >> w;
        to[u].push_back(node(v,w));
        to[v].push_back((node(u,w)));
        ans += 2ll*w;
    }
    dfs(1,0);
    for(int k = 0;k <= 2*n-2;k += 1){
        ll maxn = 0;
        for(int i = 1;i <= n;i += 1)maxn = max(maxn,f[i][k]);
        cout << ans - maxn << ' ';
    }
    cout << '\n';
}

void clear(){
    for(int i = 1;i <= n;i += 1){
        to[i].clear();
        for(int j = 0;j <= 2*n-2;j += 1)f[i][j] = g[i][j] = h[i][j] = 0;
    }
}

int main()
{
    int T;cin >> T;
    while(T--)solve(),clear();
    return 0;
}