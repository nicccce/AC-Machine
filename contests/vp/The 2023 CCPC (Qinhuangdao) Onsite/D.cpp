// https://codeforces.com/gym/104787/problem/D
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define lc id<<1
#define rc id<<1|1
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m;
        cin >> n >> m;

        vector<int> w(n+1);
        for(int i=1; i<=n; i++)
            cin >> w[i];
        
        struct node{
            int mi_val;
            int mi_pos;
        };
        vector<node> tree(4LL*n+5LL);
        vector<int> lazy(4LL*n, 0);

        auto merge = [&](node L, node R){
            if(L.mi_val <= R.mi_val)
                return L;
            return R;
        };

        function<void(int, int, int)> build = [&](int id, int l, int r){
            if(l == r)
                tree[id] = {w[l], l};
            else{   
                int mid = (l+r)>>1LL;
                build(lc, l, mid);
                build(rc, mid+1, r);
                tree[id] = merge(tree[lc], tree[rc]);
            }
        };
        build(1, 1, n);

        function<void(int, int, int)> pushdown = [&](int id, int l, int r){
            if(lazy[id]){
                tree[id].mi_val += lazy[id];
                if(l != r){
                    lazy[lc] += lazy[id];
                    lazy[rc] += lazy[id];
                }
                lazy[id] = 0;
            }
        };

        function<void(int, int, int, int, int, int)> upd = [&](int id, int st, int ed, int l, int r, int k){
            pushdown(id, st, ed);
            if(st>r || ed<l) return;
            if(l<=st && ed<=r){
                lazy[id] += k;
                pushdown(id, st, ed);
                return;
            }

            int mid = (st+ed)>>1LL;
            upd(lc, st, mid, l, r, k);
            upd(rc, mid+1, ed, l, r, k);

            tree[id] = merge(tree[lc], tree[rc]);
        };

        function<node(int, int, int, int, int)> qry = [&](int id, int st, int ed, int l, int r){
            pushdown(id, st, ed);

            if(st>r || ed<l) 
                return node{LLONG_MAX, -1};
            if(l<=st && ed<=r) 
                return tree[id];

            int mid = (st+ed)>>1LL;
            node lnode = qry(lc, st, mid, l, r);
            node rnode = qry(rc, mid+1, ed, l, r);

            if(lnode.mi_pos == -1) return rnode;
            if(rnode.mi_pos == -1) return lnode;
            return merge(lnode, rnode);
        };

        vector<PII> tick(m+1);
        for(int i=1; i<=m; i++)
            cin >> tick[i].first >> tick[i].second;
        sort(tick.begin()+1, tick.begin()+m+1);

        for(int i=1; i<=m; i++)
            upd(1, 1, n, 1, tick[i].first, -tick[i].second);

        int pt = m;
        int summ = 0;
        for(int i=1; i<=n; i++){
            node res = qry(1, 1, n, 1, n);
            summ += res.mi_val;
            cout << summ << " ";
            // cout << res.mi_pos << " ?";

            while(pt>=1 && res.mi_pos<=tick[pt].first){
                upd(1, 1, n, 1, tick[pt].first, tick[pt].second);
                pt--;
            }
            
            upd(1, 1, n, res.mi_pos, res.mi_pos, INT_MAX);

            // for(int j=1; j<=n; j++)
                // cout << qry(1, 1, n, j, j).mi_val << " ";
            // cout << "\n";
        }
        cout << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}
