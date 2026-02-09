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

int binaryReflection(int n) {
    int msbPos = 31 - __builtin_clz(n);
    int reversed = 0;
    for (int i = msbPos; i >= 0; i--) {
        reversed <<= 1;
        if (n & 1) {
            reversed |= 1;
        }
        n >>= 1;
    }
    return reversed;
}

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            int refA = binaryReflection(a);
            int refB = binaryReflection(b);
            if (refA != refB) return refA < refB;
            return a < b;
        });
        return nums;
    }
};