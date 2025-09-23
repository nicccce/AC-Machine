// https://codeforces.com/contest/2146/problem/D2
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        
        struct Trie {
            vector<array<int,2>> ch;
            vector<int> cnt;
            int idx;

            Trie() {
                ch.pb({-1, -1});
                cnt.pb(0);
                idx = 0;
            }

            void insert(int x) {
                int u = 0;
                for (int j = 0; j < 30; j++) {
                    int bit = (x >> j) & 1;
                    if (ch[u][bit] == -1) {
                        ch.pb({-1, -1});
                        cnt.pb(0);
                        ch[u][bit] = ++idx;
                    }
                    u = ch[u][bit];
                    cnt[u]++;
                }
            }

            int match(int x) {
                int u = 0, y = 0;
                for (int j = 0; j < 30; j++) {
                    int bit = (x >> j) & 1;
                    int desired = bit ^ 1;
                    int chosen;

                    if (ch[u][desired] != -1 && cnt[ch[u][desired]] > 0) {
                        chosen = desired;
                    } else {
                        chosen = bit;
                    }

                    u = ch[u][chosen];
                    if (chosen) y |= (1 << j);
                    cnt[u]--;
                }
                return y;
            }
        } trie;

        for (int i = l; i <= r; i++) {
            trie.insert(i);
        }

        vector<int> a;
        int res = 0;
        for (int i = l; i <= r; i++) {
            int y = trie.match(i);
            a.pb(y);
            res += i | y;
        }

        cout << res << '\n';
        for (auto x : a) cout << x << ' ';
        cout << '\n';
    };

    int t;
    for(cin >> t; t--; )
        solve();
    return 0;
}