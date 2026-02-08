// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 遍历所有可能的相邻子数组对
        for (int i = 0; i <= n - 2 * k; i++) {
            bool firstIncreasing = true;
            bool secondIncreasing = true;
            
            // 检查第一个子数组是否严格递增
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    firstIncreasing = false;
                    break;
                }
            }
            
            // 检查第二个子数组是否严格递增
            for (int j = i + k; j < i + 2 * k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    secondIncreasing = false;
                    break;
                }
            }
            
            if (firstIncreasing && secondIncreasing) {
                return true;
            }
        }
        
        return false;
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