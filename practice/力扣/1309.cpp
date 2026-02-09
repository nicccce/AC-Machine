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
    string freqAlphabets(string s) {
        string result;
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                result = char('a' + num - 1) + result;
                i -= 3;
            } else {
                int num = s[i] - '0';
                result = char('a' + num - 1) + result;
                i--;
            }
        }
        return result;
    }
};