// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            // 反转字母表中的位置: 'a'对应26, 'b'对应25, ..., 'z'对应1
            int reversePos = 27 - (s[i] - 'a' + 1);
            // 乘以字符串中的位置(从1开始)
            result += reversePos * (i + 1);
        }
        return result;
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