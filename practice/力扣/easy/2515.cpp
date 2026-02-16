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
 * [2515] 到目标字符串的最短距离
 */

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                ans = min(ans, min(diff, n - diff));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
