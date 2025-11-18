// https://ac.nowcoder.com/acm/contest/32708/F

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]{
        int n;
        cin >> n;
        vector<int> G[n+1];
        vector<int> b(n+1);
        for(int i=1; i<=n; i++)
            cin >> b[i];

        double mx = 0.0;
        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            int tmp = abs(b[u]+b[v]);
            mx = max(mx, (double)tmp*(double)tmp/16.0);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        function<void(int, int)> dfs = [&](int u, int fa){
            int sb1=0, sb2=0, cnm1=0, cnm2=0; // 最小、次小、最大、次大
            if(G[u].size()!=1){
            for(auto x: G[u]){
                if(b[x] < 0){
                    if(b[x] <= sb1){
                        sb2 = sb1;
                        sb1 = b[x];
                    }
                    else if(b[x] < sb2){
                        sb2 = b[x];
                    }
                }
                if(b[x] > 0){
                    if(b[x] >= cnm1){
                        cnm2 = cnm1;
                        cnm1 = b[x];
                    }
                    else if(b[x] > cnm2){
                        cnm2 = b[x];
                    }
                }
            }
            int tmp;
            tmp = max(abs(cnm1+cnm2+b[u]), abs(sb1+sb2+b[u]));
            mx = max(mx, (double)tmp*(double)tmp/36.0);
            }
            for(auto x: G[u]){
                if(x != fa) 
                    dfs(x, u);
                
            }
        };
        dfs(1, 0);

        cout << setiosflags(ios::fixed);
        cout << setprecision(10) << mx << "\n";
    };

    solve();
    return 0;
}