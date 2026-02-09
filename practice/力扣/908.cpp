// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        // 我们可以将最小值增加k，将最大值减少k
        // 这样新数组的最小值至少是min_val+k，最大值至多是max_val-k
        // 如果min_val+k >= max_val-k，那么所有元素可以变为相同的值
        int new_min = min_val + k;
        int new_max = max_val - k;
        
        if(new_min >= new_max) {
            return 0;
        } else {
            return new_max - new_min;
        }
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