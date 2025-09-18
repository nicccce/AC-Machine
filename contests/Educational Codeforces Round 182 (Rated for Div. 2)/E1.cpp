// https://codeforces.com/contest/2144/problem/E1
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> pow2(5001, 0);
    pow2[0] = 1LL;
    for (int i = 1; i <= 5000; ++i) {
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    }

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // Compute L_list
        vector<long long> L_list;
        long long cur_max = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > cur_max) {
                L_list.push_back(a[i]);
                cur_max = a[i];
            }
        }
        int kk = L_list.size();

        // Compute R_list
        vector<long long> R_list;
        cur_max = -1;
        for (int i = n; i >= 1; --i) {
            if (a[i] > cur_max) {
                R_list.push_back(a[i]);
                cur_max = a[i];
            }
        }
        reverse(R_list.begin(), R_list.end()); // Now R_list[0] = r1, R_list[m-1] = rm
        int mm = R_list.size();

        if (kk == 0 || mm == 0) {
            cout << 0 << '\n';
            continue;
        }

        long long max_a = L_list[kk - 1];

        // DP_front
        vector<vector<long long>> dp_front(n + 2, vector<long long>(kk + 1, 0LL));
        dp_front[0][0] = 1LL;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= kk; ++j) {
                // skip
                dp_front[i + 1][j] = (dp_front[i + 1][j] + dp_front[i][j]) % MOD;
                // include a[i+1]
                long long val = a[i + 1];
                if (j == 0) {
                    if (kk >= 1 && val == L_list[0]) {
                        dp_front[i + 1][1] = (dp_front[i + 1][1] + dp_front[i][0]) % MOD;
                    }
                } else {
                    if (val > L_list[j - 1]) {
                        if (j < kk && val == L_list[j]) {
                            dp_front[i + 1][j + 1] = (dp_front[i + 1][j + 1] + dp_front[i][j]) % MOD;
                        }
                    } else {
                        dp_front[i + 1][j] = (dp_front[i + 1][j] + dp_front[i][j]) % MOD;
                    }
                }
            }
        }

        // DP_back
        vector<vector<long long>> dp_back(n + 2, vector<long long>(mm + 1, 0LL));
        dp_back[n + 1][0] = 1LL;
        for (int i = n; i >= 1; --i) {
            for (int s = 0; s <= mm; ++s) {
                // skip
                dp_back[i][s] = (dp_back[i][s] + dp_back[i + 1][s]) % MOD;
                // include a[i]
                long long val = a[i];
                if (s == 0) {
                    if (mm >= 1 && val == R_list[0]) {
                        dp_back[i][1] = (dp_back[i][1] + dp_back[i + 1][0]) % MOD;
                    }
                } else {
                    if (val > R_list[s - 1]) {
                        if (s < mm && val == R_list[s]) {
                            dp_back[i][s + 1] = (dp_back[i][s + 1] + dp_back[i + 1][s]) % MOD;
                        }
                    } else {
                        dp_back[i][s] = (dp_back[i][s] + dp_back[i + 1][s]) % MOD;
                    }
                }
            }
        }

        // max_pos
        vector<int> max_pos;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == max_a) {
                max_pos.push_back(i);
            }
        }

        long long ans = 0LL;
        for (size_t uu = 0; uu < max_pos.size(); ++uu) {
            int ff = max_pos[uu];
            for (size_t vv = uu; vv < max_pos.size(); ++vv) {
                int ll = max_pos[vv];
                long long ways = dp_front[ff][kk - 1];
                int cnt_free = ll - ff - 1;
                if (cnt_free < 0) continue;
                ways = (ways * pow2[cnt_free]) % MOD;
                ways = (ways * dp_back[ll + 1][mm - 1]) % MOD;
                ans = (ans + ways) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}