#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int res = 0;
        for (auto [x, c] : cnt) {
            if (cnt.count(x + 1)) {
                res = max(res, c + cnt[x + 1]);
            }
        }
        return res;
    }
};