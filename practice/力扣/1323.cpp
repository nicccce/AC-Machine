// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        // 找到第一个'6'并将其改为'9'，这样可以获得最大值
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
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