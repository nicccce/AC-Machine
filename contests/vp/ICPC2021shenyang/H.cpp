#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int INF=LONG_LONG_MAX;
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

    vector<int> dist(n + 1, -1);
    vector<int> vis_e(m, 0);
    long long ans = 0; 

    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1 || g[i].empty()) continue;

        vector<int> ce; 
        bool full = false;
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& edge : g[u]) {
                int v = edge.first;
                int id = edge.second;

                if (!vis_e[id]) {
                    vis_e[id] = 1;
                    ce.push_back(id);
                }

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if ((dist[u] % 2) == (dist[v] % 2)) {
                    full = true;
                }
            }
        }
        if (ce.size() % 2 == 0) continue;

        if (full) {
            int mn = INF;
            for (int id : ce) {
                mn = min(mn, ew[id]);
            }
            ans += mn;
        } else {
            int cnt1 = 0;
            int min1 = INF, min0 = INF;

            for (int id : ce) {
                int u = ee[id].first;
                int v = ee[id].second;
                int layer = min(dist[u], dist[v]);

                if (layer % 2 == 0) {
                    cnt1++;
                    min1 = min(min1, ew[id]);
                } else {
                    min0 = min(min0, ew[id]);
                }
            }

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