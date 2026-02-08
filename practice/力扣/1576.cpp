// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ((i == 0 || s[i-1] != c) && (i == n-1 || s[i+1] != c)) {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        return s;
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