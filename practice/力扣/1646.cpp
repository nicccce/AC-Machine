// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = 1;
        
        for (int i = 1; 2 * i <= n || 2 * i + 1 <= n; i++) {
            if (2 * i <= n) {
                nums[2 * i] = nums[i];
            }
            if (2 * i + 1 <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
        }
        
        int maxVal = 0;
        for (int i = 0; i <= n; i++) {
            maxVal = max(maxVal, nums[i]);
        }
        
        return maxVal;
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