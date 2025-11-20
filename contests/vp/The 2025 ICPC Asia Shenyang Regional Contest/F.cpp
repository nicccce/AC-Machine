// https://qoj.ac/contest/2606/problem/14945
#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<int> G[n+1];
        bool neighbor = 0;
        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);

            if((u==x && v==y) || (u==y && v==x)){
                neighbor = 1;
            }
        }

        vector<PII> ans;
        map<PII, bool> vis;

        // 非邻居，直接构造
        if(!neighbor){
            for(auto u: G[x]){
                ans.push_back({u, x});
                vis[{x, u}] = 1;
                vis[{u, x}] = 1;
            }
            for(auto u: G[y]){
                ans.push_back({u, y});
                vis[{y, u}] = 1;
                vis[{u, y}] = 1;
            }
            for(int i=1; i<=n; i++){
                for(auto u: G[i]){
                    if(!vis[{u, i}] && !vis[{i, u}]){
                        ans.push_back({u, i});
                        vis[{u, i}] = 1;
                        vis[{i, u}] = 1;
                    }
                }
            }
        }
        // 是邻居，需要找环
        else{
            vector<int> chain, nowRing;
            bool findRing = 0;

            vector<int> d(n+1), pre(n+1);
            auto dij = [&](int st, int delA, int delB){
                priority_queue<PII, vector<PII>, greater<PII>> pq;
                for(int i=1; i<=n; i++){
                    d[i] = INT_MAX;
                    pre[i] = -1;
                }
                d[st] = 0;
                vector<bool> vis(n+1, 0);
                pq.push({0, st});

                while(pq.size()){
                    PII p = pq.top();
                    pq.pop();
                    int v = p.second;

                    if(vis[v])
                        continue;
                    vis[v] = 1;
                    for(int e: G[v]){
                        if(vis[e])
                            continue;
                        if((e==delA && v==delB) || (e==delB && v==delA))
                            continue;

                        if(d[e] > d[v]+1){
                            d[e] = d[v]+1;
                            pre[e] = v;
                            pq.push({d[e], e});
                        }
                    }
                }
            };

            auto findRoot = [&](int st, int ed){
                vector<int> path;
                int cur = ed;
                while(cur != -1){
                    path.push_back(cur);
                    cur = pre[cur];
                }
                reverse(path.begin(), path.end());
                return path;
            };

            auto FINDCIRCLE = [&](){
                // 1. x,y在环内
                dij(x, x, y);
                if(d[y] == INT_MAX)
                    findRing = 0;
                else{
                    findRing = 1;
                    nowRing = findRoot(x, y);

                    for(auto u: nowRing)
                        chain.push_back(u);
                    chain.push_back(x);

                    return;
                }

                // 2. x靠近环
                if(!findRing){
                    queue<int> qe;
                    vector<int> fa(n+1, -1); // bfs前序节点
                    vector<bool> viss(n+1, 0);
                    qe.push(x);
                    viss[x]=1, viss[y]=1;
                    fa[x] = y;
                    chain.clear();

                    while(!qe.empty()){
                        int cur = qe.front();
                        qe.pop();

                        for(auto nxt: G[cur]){
                            if(viss[nxt])
                                continue;

                            dij(cur, cur, nxt);
                            if(d[nxt] != INT_MAX){  // 找到最小环
                                findRing = 1;

                                // 先构建链
                                int curr = cur;
                                while(curr != -1){
                                    chain.push_back(curr);
                                    curr = fa[curr];
                                }
                                reverse(chain.begin(), chain.end());
                                chain.pop_back();

                                // 再构建环
                                nowRing = findRoot(cur, nxt);
                                
                                for(auto u: nowRing)
                                    chain.push_back(u);
                                chain.push_back(cur);

                                return;
                            }
                            else{
                                fa[nxt] = cur;
                                viss[nxt] = 1;
                                qe.push(nxt);
                            }
                        }
                    }
                }

                // 3. y靠近环
                if(!findRing){
                    queue<int> qe;
                    vector<int> fa(n+1, -1); // bfs前序节点
                    vector<bool> viss(n+1, 0);
                    qe.push(y);
                    viss[x]=1, viss[y]=1;
                    fa[y] = x;
                    chain.clear();

                    while(!qe.empty()){
                        int cur = qe.front();
                        qe.pop();

                        for(auto nxt: G[cur]){
                            if(viss[nxt])
                                continue;

                            dij(cur, cur, nxt);
                            if(d[nxt] != INT_MAX){  // 找到最小环
                                findRing = 1;

                                // 先构建链
                                int curr = cur;
                                while(curr != -1){
                                    chain.push_back(curr);
                                    curr = fa[curr];
                                }
                                reverse(chain.begin(), chain.end());
                                chain.pop_back();

                                // 再构建环
                                nowRing = findRoot(cur, nxt);
                                
                                for(auto u: nowRing)
                                    chain.push_back(u);
                                chain.push_back(cur);

                                // for(auto p: chain)
                                //     cout << p << " ";
                                // cout << "\n";

                                return;
                            }
                            else{
                                fa[nxt] = cur;
                                viss[nxt] = 1;
                                qe.push(nxt);
                            }
                        }
                    }
                }
            };
            FINDCIRCLE();
            
            if(!findRing){
                cout << "No\n";
                return;
            }
            else{
                // 环链上的边
                for(int i=0; i<chain.size()-1; i++){
                    ans.push_back({chain[i], chain[i+1]});
                    vis[{chain[i], chain[i+1]}] = 1;
                    vis[{chain[i+1], chain[i]}] = 1;
                }
                // 指向环链的边
                for(int i=0; i<chain.size(); i++){
                    for(auto u: G[chain[i]]){
                        if(!vis[{u, chain[i]}]){
                            ans.push_back({u, chain[i]});
                            vis[{u, chain[i]}] = 1;
                            vis[{chain[i], u}] = 1;
                        }
                    }
                }
                // 其余边
                for(int i=1; i<=n; i++){
                    for(auto u: G[i]){
                        if(!vis[{u, i}] && !vis[{i, u}]){
                            ans.push_back({u, i});
                            vis[{u, i}] = 1;
                            vis[{i, u}] = 1;
                        }
                    }
                }
            }
        }

        cout << "Yes\n";
        for(auto [u, v]: ans)
            cout << u << " " << v << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}