#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
// 我怎么要没钱了，怎么办，没钱了没钱了没钱了没钱了没钱了没钱了没钱了没钱了
// 唉，这几把程序怎么这么难写
// 不会写了，不如写点注释
// 这注释真有用吧
// 怎么有人vscode都没打开
// 写个damn啊
// 无敌了，还在写注释
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
            int tmp;
    auto solve = [&]() {
        int n, q;
        cin >> n >> q;
        
        vector<int> g[n + 1];
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            
            g[u].pb(v);
            g[v].pb(u);
        }
        
        vector<int> son_size(n + 1), daddy(n + 1);
        function<void(int, int)> dfs = [&](int u, int fa) {
            for(int v : g[u]) {
                if(v != fa) {
                    dfs(v, u);
                    son_size[u] += son_size[v];
                    daddy[v] = u;
                }
            }
            son_size[u]++;
        };
        dfs(1, 0);
        vector<int> ans(n+1);
        function<void(int, int, int, int)> dfs2 = [&](int u, int fa, int cnt2, int cnt5) {
            tmp=u;
            int tmp2=0,tmp5=0;
            while (tmp%2==0)
            {
                tmp2+=1;
                tmp/=2;
            }
            while (tmp%5==0)
            {
                tmp5+=1;
                tmp/=5;
            }
            for(int v : g[u]) {
                if(v != fa) {
                    dfs2(v, u,cnt2+tmp2*(son_size[u]-son_size[v]),cnt5+tmp5*(son_size[u]-son_size[v]));
                }
            }
            ans[u]=min(cnt2+son_size[u]*tmp2,cnt5+son_size[u]*tmp5);
        };
        dfs2(1,0,0,0);

        while(q--) {
            int x; cin >> x;

            cout<<ans[x]<<'\n';
        }
        
    };
    
    // int t;
    // for(cin >> t; t--;)
    solve();
    return 0;
}