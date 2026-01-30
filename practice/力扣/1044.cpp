// https://leetcode.cn/problems/longest-duplicate-substring/description/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}
class Solution {
public:
    int check(const vector<int> & arr, int m, int a1, int a2, int mod1, int mod2) {
        int n = arr.size();
        ll aL1 = qpow(a1, m, mod1);
        ll aL2 = qpow(a2, m, mod2);
        ll h1 = 0, h2 = 0;
        for (int i = 0; i < m; ++i) {
            h1 = (h1 * a1 % mod1 + arr[i]) % mod1;
            h2 = (h2 * a2 % mod2 + arr[i]) % mod2;
            if (h1 < 0) {
                h1 += mod1;
            }
            if (h2 < 0) {
                h2 += mod2;
            }
        }
        set<pll> seen;
        seen.emplace(h1, h2);
        for (int start = 1; start <= n - m; ++start) {
            h1 = (h1 * a1 % mod1 - arr[start - 1] * aL1 % mod1 + arr[start + m - 1]) % mod1;
            h2 = (h2 * a2 % mod2 - arr[start - 1] * aL2 % mod2 + arr[start + m - 1]) % mod2;
            if (h1 < 0) {
                h1 += mod1;
            }
            if (h2 < 0) {
                h2 += mod2;
            }
            if (seen.count(make_pair(h1, h2))) {
                return start;
            }
            seen.emplace(h1, h2);
        }
        return -1;
    }

    string longestDupSubstring(string s) {
        srand((unsigned)time(NULL));
        int a1 = random()%75 + 26;
        int a2 = random()%75 + 26;
        int mod1 = random()%(INT_MAX - 1000000006) + 1000000006;
        int mod2 = random()%(INT_MAX - 1000000006) + 1000000006;
        int n = s.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = s[i] - 'a';
        }
        int l = 1, r = n - 1;
        int length = 0, start = -1;
        while (l <= r) {
            int m = l + (r - l + 1) / 2;
            int idx = check(arr, m, a1, a2, mod1, mod2);
            if (idx != -1) {
                l = m + 1;
                length = m;
                start = idx;
            } else {
                r = m - 1;
            }
        }
        return start != -1 ? s.substr(start, length) : "";
    }
};