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
 * [3803] 统计残差前缀
 */

class Solution {
public:
    int residuePrefixes(string s) {
        int cnt[26] = {0}, distinct = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 0) distinct++;
            cnt[s[i] - 'a']++;
            if (distinct == (i + 1) % 3) res++;
        }
        return res;
    }
};
