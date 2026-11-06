#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=300005;
        int group[maxn];
        inline int findroot(int x) {
            if (x == group[x])
                return x;
            return group[x] = findroot(group[x]);
        }
        inline void unite(int a, int b) {
            int ra = findroot(a);
            int rb = findroot(b);
            if (ra != rb)
                group[ra] = rb;
        }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {

        int n;
        cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n%2==0){
            cout<<n+1<<'\n';
            return;
        }
        auto check=[&](int x, int y) -> bool {
            for (int i = 1; i <= n; i++)
                group[i] = i;
            auto dfs = [&](auto& self, int u, int p) -> void {
                for (int v : g[u]) {
                    if (v != p && v != x) {
                        unite(u, v);
                        self(self, v, u);
                    }
                }
            };
            
            for (int v : g[x]) {
                dfs(dfs, v, x);
            }
            
            for (int i = 1; i <= n; i++) {
                if (i == x) continue;
                int j = y - i;
                if (j >= 1 && j <= n && j != i) {
                    if (findroot(i) != findroot(j)) {
                        return true;
                    }
                }
            }
            return false;
        };
        int k = (n - 1) / 2;
        if (check(1, 2*k + 3)) {
            cout << 2*k + 3 << '\n';
        } else if (check(2*k + 1, 2*k + 1)) {
            cout << 2*k + 1 << '\n';
        } else if (check(k + 1, 2*k + 2)) {
            cout << 2*k + 2 << '\n';
        } else {
            cout << 2*k + 1 << '\n';
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}