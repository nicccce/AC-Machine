#include<bits/stdc++.h>
#define N 500017

using namespace std;

int n,m,dfn[N];

void fir(){
    cin >> n >> m;
    vector<vector<int>>e(m+1,vector<int>(2));
    for(int i = 1;i <= m;i += 1)cin >> e[i][0] >> e[i][1];
    int c;cin >> c;
    int tim = 0;
    for(int i = 1;i <= c;i += 1){
        int x;cin >> x;
        dfn[x] = ++tim;
    }
    for(int i = 1;i <= n;i += 1)
        if(!dfn[i])dfn[i] = ++tim;
    for(int i = 1;i <= m;i += 1){
        int u,v;u = e[i][0],v = e[i][1];
        if(dfn[u] > dfn[v])swap(u,v);
        if(dfn[u] == 1 && dfn[v] == c)cout << v << ' ' << u << '\n';
        else cout << u << ' ' << v << '\n';
    }
}

void sec(){
    cin >> n >> m;
    vector<int>to[n+1];    
    set<int>inver[n+1];
    for(int i = 1;i <= m;i += 1){
        int u,v;cin >> u >> v;
        to[u].push_back(v);
    }
    int tim = 0,top = 0,co = 0;
    vector<int>dfn(n+1),low(n+1),col(n+1),st(n+1);
    queue<int> qu;
    function<void(int)> dfs=[&](int u){
        dfn[u] = low[u] = ++tim;st[++top] = u;
        for(int i = 0;i < to[u].size();i += 1){
            int v = to[u][i];
            if(!dfn[v]){
                dfs(v);
                low[u] = min(low[u],low[v]);
            }
            else if(!col[v])low[u] = min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u]){
            col[u] = u;
            while(st[top] != u)co = col[st[top--]] = u;
            top--;
        }
    };
    for(int i = 1;i <= n;i += 1)
        if(!dfn[i])dfs(i);
    vector<int>in(n+1),out(n+1);
    queue<int>q;
    for(int i = 1;i <= n;i += 1){
        if(col[i] != co)continue;
        for(int j = 0;j < to[i].size();j += 1){
            int v = to[i][j];
            if(col[v] != co)continue;
            in[v]++;
            inver[v].insert(i);
            out[v]++;
        }
    }
    vector<int>toto(n+1);
    for(int i=1;i<=n;i++){
        if(inver[i].size()==1){
            qu.push(i);
            toto[*inver[i].begin()]=i;
        }
    }
    while (qu.size()){
        int v=qu.front();
        qu.pop();
        int u=*inver[v].begin();
        for(auto i:to[u]){
            if(col[i] != co)continue;
            inver[i].erase(u);
            if(inver[i].size()==1){
                qu.push(i);
                toto[*inver[i].begin()]=i;
            }
        }

    }
    int now=co;
    // cout<<co<<' ';
    do{
        now=toto[now];
        cout<<now<<' ';
    }
    while (now!=co);
    
    // while(q.size()){
    //     int u = q.front();q.pop();
    //     cout << u << ' ';
    //     for(int i = 0;i < to[u].size();i += 1){
    //         int v = to[u][i];
    //         if(col[v] != co)continue;
    //         in[v]--;
    //         if(!in[v])q.push(v);
    //     }
    // }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int op;cin >> op;
    if(op == 1)fir();
    else sec();
    return 0;
}