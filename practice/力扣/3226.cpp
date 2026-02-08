// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minChanges(int n, int k) {
        // If k has a bit set to 1 that n doesn't have, it's impossible
        if ((n & k) != k) {
            return -1;
        }
        
        // Count the number of 1s in n that are 0s in k
        int changes = 0;
        int xorResult = n ^ k;  // This gives us the positions where bits differ
        
        // Count the set bits in xorResult (these are positions where n has 1 but k has 0)
        changes = __builtin_popcount(xorResult);
        
        return changes;
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