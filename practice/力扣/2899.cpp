// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int k = 0;  // Count of consecutive -1s
        
        for (int num : nums) {
            if (num > 0) {
                seen.insert(seen.begin(), num);  // Add to the front of seen
                k = 0;  // Reset the consecutive -1 counter
            } else {
                k++;  // Increment consecutive -1 counter
                if (k <= seen.size()) {
                    ans.push_back(seen[k-1]);  // 1-indexed access
                } else {
                    ans.push_back(-1);
                }
            }
        }
        
        return ans;
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