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
 * [2437] 有效时间的数目
 */

class Solution {
public:
    int countTime(string time) {
        int h = 1, m = 1;
        if (time[0] == '?') {
            if (time[1] == '?') h = 24;
            else if (time[1] <= '3') h = 3;
            else h = 2;
        } else if (time[1] == '?') {
            if (time[0] == '0' || time[0] == '1') h = 10;
            else h = 4;
        }
        if (time[3] == '?') {
            if (time[4] == '?') m = 60;
            else if (time[4] <= '5') m = 6;
            else m = 6;
        } else if (time[4] == '?') {
            if (time[3] <= '4') m = 10;
            else m = 10;
        }
        return h * m;
    }
};
