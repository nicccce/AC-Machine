// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        
        if (n == 1) {
            return true;
        }
        
        // Remove all factors of 2
        while (n % 2 == 0) {
            n /= 2;
        }
        
        // Remove all factors of 3
        while (n % 3 == 0) {
            n /= 3;
        }
        
        // Remove all factors of 5
        while (n % 5 == 0) {
            n /= 5;
        }
        
        // If n is 1 after removing all factors of 2, 3, and 5, it's an ugly number
        return n == 1;
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