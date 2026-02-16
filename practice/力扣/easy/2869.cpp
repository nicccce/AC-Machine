#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> needed;
        for (int i = 1; i <= k; i++) {
            needed.insert(i);
        }
        
        int operations = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            operations++;
            if (needed.count(nums[i])) {
                needed.erase(nums[i]);
                if (needed.empty()) {
                    break;
                }
            }
        }
        
        return operations;
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