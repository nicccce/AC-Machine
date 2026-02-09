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

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string a, b;
        for (int i = 0; i < 4; ++i) {
            if (i % 2 == 0) a += s1[i];
            else b += s1[i];
        }
        string c, d;
        for (int i = 0; i < 4; ++i) {
            if (i % 2 == 0) c += s2[i];
            else d += s2[i];
        }
        sort(a.begin(), a.end());
        sort(c.begin(), c.end());
        sort(b.begin(), b.end());
        sort(d.begin(), d.end());
        return a == c && b == d;
    }
};
