// https://leetcode.cn/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for (int x : nums) {
            auto it = lower_bound(g.begin(),g.end(),x);
            if (it == g.end()) {
                g.push_back(x);
            } else {
                *it = x;
            }
        }
        return g.size();
    }
};


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
int ex_gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int solve_linear_congruence_equation(int a, int b, int n)
{
    int x, y;
    int d = ex_gcd(a, n, x, y);
    if (b % d)
        return -1;
    n /= d;
    return ((long long)x * (b / d) % n + n) % n;
}
