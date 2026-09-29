#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LOG 20 // 保证2^LOG > 最大节点数；maxn约2e5时取20
const int maxn = 3e5;

// 链式前向星：增加了边权 w
struct Edge {
    int to, next, w;
} edge[maxn << 1];
int head[maxn], idx;

// fa[x][i]：x的第2^i个祖先；deep[x]：x的深度
int fa[maxn][LOG], deep[maxn];
// 新增：sz[x] 为 x 的子树大小；dist[x] 为 x 到根节点的带权距离
int sz[maxn], dist[maxn];

void init() {
    memset(head, -1, sizeof head);
    memset(fa, 0, sizeof fa);
    memset(deep, 0, sizeof deep);
    idx = 0;
}

// 添加有向边，带边权
void addEdge(int u, int v, int w) {
    edge[idx] = {v, head[u], w};
    head[u] = idx++;
}

// 计算深度、倍增数组、子树大小、以及到根的带权距离
void dfs(int x, int father, int d) {
    deep[x] = deep[father] + 1;
    fa[x][0] = father;
    sz[x] = 1;
    dist[x] = d;
    
    for (int i = 1; i < LOG; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        
    for (int i = head[x]; i != -1; i = edge[i].next) {
        int y = edge[i].to;
        if (y != father) {
            dfs(y, x, d + edge[i].w);
            sz[x] += sz[y];
        }
    }
}

// 查询LCA，逻辑不变
int LCA(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--)
        if (deep[x] - (1 << i) >= deep[y])
            x = fa[x][i];
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    auto solve = [&]() {
        int n, m;
        if (!(cin >> n >> m)) return;
        
        init();
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            addEdge(u, v, w); 
            addEdge(v, u, w);
        }
        
        // 预处理
        dfs(1, 0, 0);

        while (m--) {
            int x, y, z;
            cin >> x >> y >> z;
            
            int lca = LCA(x, y);
            
            // 1. 暴力提取 x 到 y 的有序路径
            vector<int> path_x, path_y;
            int curr = x;
            while (curr != lca) {
                path_x.push_back(curr);
                curr = fa[curr][0];
            }
            curr = y;
            while (curr != lca) {
                path_y.push_back(curr);
                curr = fa[curr][0];
            }
            
            // 拼接出完整的有序路径 P
            vector<int> P = path_x;
            P.push_back(lca);
            for (int i = (int)path_y.size() - 1; i >= 0; i--) {
                P.push_back(path_y[i]);
            }
            
            int k = P.size();
            
            // 如果x和y相同，新边是个自环，没有任何最短路会减小
            if (k <= 1) {
                cout << 0 << "\n";
                continue;
            }
            
            // 2. O(1) 计算路径上每个点对应的连通块权重 W
            vector<int> W(k);
            for (int i = 0; i < k; ++i) {
                int node = P[i];
                // 初始化大小
                W[i] = (node == lca) ? n : sz[node];
                
                // 统一容斥：只要路径上的相邻节点是自己的"直接儿子"，就减去它的 sz
                // 巧妙避免了复杂的左右分支讨论
                if (i > 0 && fa[P[i-1]][0] == node) W[i] -= sz[P[i-1]];
                if (i < k - 1 && fa[P[i+1]][0] == node) W[i] -= sz[P[i+1]];
            }
            
            // 3. 计算路径前缀距离 D
            vector<int> D(k, 0);
            for (int i = 1; i < k; ++i) {
                D[i] = D[i-1] + abs(dist[P[i]] - dist[P[i-1]]);
            }
            
            // 计算 W 的后缀和，方便后续双指针统计
            vector<int> suff_W(k + 1, 0);
            for (int i = k - 1; i >= 0; --i) {
                suff_W[i] = suff_W[i+1] + W[i];
            }
            
            // 4. 双指针扫描满足条件 2*(D[j] - D[i]) > z + D[k-1] 的 (i, j) 对
            int ans = 0;
            int T = z + D[k-1];
            int j = 1;
            
            for (int i = 0; i < k; ++i) {
                j = max(j, i + 1); // 保证 j > i
                while (j < k && 2 * (D[j] - D[i]) <= T) {
                    j++;
                }
                if (j < k) {
                    ans += W[i] * suff_W[j]; // 若 j 满足，则 [j, k-1] 均满足
                }
            }
            cout << ans << "\n";
        }
    };
    
    solve();
    return 0;
}