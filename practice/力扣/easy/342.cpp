// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        
        // 4的幂必须是2的幂，且二进制表示中1只在奇数位上
        // 同时，4的幂模3余1（因为4^k = (3+1)^k ≡ 1 (mod 3)）
        return (n & (n-1)) == 0 && (n & 0x55555555) != 0 && n % 3 == 1;
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