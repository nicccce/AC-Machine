#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
      int n,m,q;cin>>n>>m>>q;
      vector<pair<int,int>> a(m+1);
      for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
      }
      vector<int> ed(m+1,m+1);
      deque<pair<int,int>> q0,q1;
      for(int i=1;i<=m;i++){
        auto [o,x]=a[i];
        if(o==0){
            while (!q0.empty()&&q0.back().first<=x){
                ed[q0.back().second]=i;q0.pop_back();
            }q0.push_back({x,i});
            int lst=0;
            while (!q1.empty()&&q1.front().first<=x+1){
                lst=q1.front().second;
                ed[lst]=i;q1.pop_front();
            }
            if(lst&&x<n){
                ed[lst]=m+1;
                q1.push_front({x+1,lst});
            }
        }else{
            while (!q1.empty()&&q1.back().first>=x) {
                    ed[q1.back().second]=i;
                    q1.pop_back();
                }
                q1.push_back({x,i});
                int lst=0;
                while (!q0.empty()&&q0.front().first>=x-1) {
                    lst=q0.front().second;
                    ed[lst]=i;
                    q0.pop_front();
                }
                if (lst&&x>1) {
                    ed[lst]=m+1;
                    q0.push_front({x-1,lst});
                }
        }
      }
        vector<int> sum((m + 2) << 2, 0);
        vector<int> ans(q + 1, 0);
        struct node {
            int id, y, f;
            node(int _id = 0, int _y = 0, int _f = 0) {
                id = _id, y = _y, f = _f;
            }
        };
        vector<vector<node>> vec(m + 1);
        auto modify = [&](auto& self, int k, int l, int r, int pos) -> void {
            if (l == r) {
                sum[k]++;
                return;
            }
            int mid = (l + r) >> 1;
            if (pos <= mid) self(self, k << 1, l, mid, pos);
            else self(self, k << 1 | 1, mid + 1, r, pos);
            sum[k] = sum[k << 1] + sum[k << 1 | 1];
        };

        auto query = [&](auto& self, int k, int l, int r, int ql, int qr) -> int {
            if (ql > qr) return 0;
            if (l >= ql && r <= qr) return sum[k];
            int res = 0, mid = (l + r) >> 1;
            if (ql <= mid) res += self(self, k << 1, l, mid, ql, qr);
            if (mid < qr) res += self(self, k << 1 | 1, mid + 1, r, ql, qr);
            return res;
        };

        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            vec[l - 1].push_back(node(i, r, -1));
            vec[r].push_back(node(i, r, 1));
        }

        for (int i = 1; i <= m; i++) {
            modify(modify, 1, 1, m + 1, ed[i]);
            for (auto& nd : vec[i]) {
                ans[nd.id] += nd.f * query(query, 1, 1, m + 1, nd.y + 1, m + 1);
            }
        }

        for (int i = 1; i <= q; i++) {
            cout << ans[i] << '\n';
        }
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
}