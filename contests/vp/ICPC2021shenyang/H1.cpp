#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int INF=2e9;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> ew(m);
    vector<pair<int,int>> ee(m); 
    int ssum=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ew[i]=w;
        ssum+=w;
        ee[i]={u,v};
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
vector<int> dist(n + 1, -1); // -1 表示点未访问，>=0 表示 BFS 层数
    vector<int> vis_e(m, 0);     // 标记边是否已被加入当前连通分量
    long long ans = 0;           // 累加答案，用 long long 防溢出

    for (int i = 1; i <= n; i++) {
        // 如果点 i 已经访问过，或者是个没有边的孤立点，直接跳过
        if (dist[i] != -1 || g[i].empty()) continue;

        vector<int> ce;       // 存当前连通分量里的所有边 id
        bool full = false;    // 标记是否触发了“全染色”（存在奇环）
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& edge : g[u]) {
                int v = edge.first;
                int id = edge.second;

                // 每条无向边只收集一次
                if (!vis_e[id]) {
                    vis_e[id] = 1;
                    ce.push_back(id);
                }

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if ((dist[u] % 2) == (dist[v] % 2)) {
                    // 两端点层数奇偶性相同 -> 存在奇环，交替染色会全覆盖
                    full = true;
                }
            }
        }

        // 1. 如果连通分量里面有偶数条边，就不管
        if (ce.size() % 2 == 0) continue;

        // 2. 如果有奇数条边：
        if (full) {
            // 情况 A：全染色了，所有边都是 1，直接取整个连通分量边权的最小值
            int mn = INF;
            for (int id : ce) {
                mn = min(mn, ew[id]);
            }
            ans += mn;
        } else {
            // 情况 B：正常隔一个染色，按边所在的层数奇偶性分为 1(染色) 和 0(未染色)
            int cnt1 = 0;
            int min1 = INF, min0 = INF;

            for (int id : ce) {
                int u = ee[id].first;
                int v = ee[id].second;
                int layer = min(dist[u], dist[v]); // 边所在的 BFS 层

                if (layer % 2 == 0) {
                    // 第 0, 2, 4... 层为染色 (1)
                    cnt1++;
                    min1 = min(min1, ew[id]);
                } else {
                    // 第 1, 3, 5... 层为未染色 (0)
                    min0 = min(min0, ew[id]);
                }
            }

            // 如果被染色(1)的是奇数个，取 min1；否则取未染色(0)中的最小值 min0
            if (cnt1 % 2 == 1) {
                ans += min1;
            } else {
                ans += min0;
            }
        }
    }

    cout << ssum - ans << "\n";
	return 0;
}