#include<bits/stdc++.h>
using namespace std;
int n,m;

struct node{
    int v,id;
    node(int _v = 0,int _id = 0){
        v = _v,id = _id;
    }
};

#define N 200017
bool vis[N],col[N];
int val[N];
int w[2];
int fa[N];
vector<int> to[N];
void dfs(int u,int f){
    vis[u] = 1;
    for(int i = 0;i < to[u].size();i += 1){
        int v = to[u][i];
        if(v == f)continue;
        dfs(v,u);
    }
}

void bfs(){
    queue<int>q;
    for(int i = 0;i < to[0].size();i += 1)
        col[to[0][i]] = 1,val[to[0][i]] = ++w[1],fa[to[0][i]]=0,q.push(to[0][i]);
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = 1;
        for(int i = 0;i < to[u].size();i += 1){
            int v = to[u][i];
            if(vis[v])continue;
            col[v] = col[u]^1;
            val[v] = ++w[col[v]];
            fa[v] = u;
            q.push(v);
        }
    }
}

bool cmp(node A,node B){
    return A.v < B.v;
}

void cat()
{
    cin >> n >> m;
    w[0]=1;val[0]=1;
    for(int i = 1;i <= m;i += 1){
        int a,b;cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int i = 1;i <= n;i += 1)
        if(!vis[i]){
            dfs(i,0);
            to[0].push_back(i);
        }
    for(int i=1;i<=n;i++)vis[i]=0;
    bfs();
    for(int i = 1;i <= n;i += 1)
        if(col[i])cout << val[fa[i]]+val[i]-1+n << ' ';
        else cout << val[fa[i]]+val[i]-1 << ' ';
    cout << '\n';
}

void dog(){
    cin >> n;
    vector<int> vv(n+1);
    vector<node> vec[2];
    for(int i = 1;i <= n;i += 1)cin >> vv[i];
    for(int i = 1;i <= n;i += 1){
        if(vv[i] > n)vec[1].push_back(node(vv[i],i));
        else vec[0].push_back(node(vv[i],i));
    }
    sort(vec[1].begin(),vec[1].end(),cmp);
    sort(vec[0].begin(),vec[0].end(),cmp);
    for(int i = 0;i < vec[0].size();i += 1){
        int v = vec[0][i].v-i-1;
        if(v>0)
        to[vec[1][v-1].id].push_back(vec[0][i].id);
    }
    for(int i = 0;i < vec[1].size();i += 1){
        int v = vec[1][i].v-i-1-n;
        if(v>0)
        to[vec[0][v-1].id].push_back(vec[1][i].id);
    }
    m = 0;
    for(int i = 1;i <= n;i += 1)m += to[i].size();
    cout << m << '\n';
    for(int i = 1;i <= n;i += 1){
        for(int j = 0;j < to[i].size();j += 1)
            cout << i << ' ' << to[i][j] << '\n';
    }
}

void clear(){
    w[0] = w[1] = 0;
    for(int i = 0;i <= n;i += 1)vis[i] = 0,to[i].clear();
}

int main()
{
    string str;cin >> str;
    int T;
    if(str == "cat"){
        cin >> T;
        while(T--)cat(),clear();
    }
    else {
        cin >> T;
        while(T--)dog(),clear();
    }
    return 0;
}
/*
cat
10 7
10 9
7 9
10 5
4 8
3 7
4 10
1 2

dog
4
1
2
4
7 2 4 5
7
13 12 8 11 2 9 6
10
11 13 18 16 10 4 7 18 19 2
*/