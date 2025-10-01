#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N = 2e6 + 10, M = 4e6 + 10;

int n;
vector<int> g[N];
int dep[N], d[N], v[N], ans[N], parent[N];
int tree[M];

void update(int idx, int val) {
    while (idx < M) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int s = 0;
    while (idx) {
        s += tree[idx];
        idx -= idx & -idx;
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) cin >> d[i];

    queue<int> q;
    q.push(1);
    dep[1] = 0;
    parent[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (v == parent[u]) continue;
            dep[v] = dep[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) v[i] = dep[i] + d[i];

    stack<pair<int, int>> st;
    st.push({1, 0});
    while (!st.empty()) {
        int u = st.top().first;
        int &idx = st.top().second;
        if (idx == 0) {
            update(v[u] + 1, 1);
            ans[u] = (dep[u] + 1) - query(dep[u]);
        }
        if (idx < g[u].size()) {
            int next = g[u][idx];
            idx++;
            if (next == parent[u]) continue;
            st.push({next, 0});
        } else {
            update(v[u] + 1, -1);
            st.pop();
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}