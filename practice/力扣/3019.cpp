// 
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
                                                                                                                                                                             


/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 *
 * [3019] 按键变更的次数
 */

// @lc code=start
class Solution {
public:
    int countKeyChanges(string s) {
        if (s.empty()) return 0;
        
        int changes = 0;
        char prev = tolower(s[0]);
        
        for (int i = 1; i < s.length(); i++) {
            char curr = tolower(s[i]);
            if (curr != prev) {
                changes++;
            }
            prev = curr;
        }
        
        return changes;
    }
};
// @lc code=end