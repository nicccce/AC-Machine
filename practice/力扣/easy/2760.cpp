// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if current element is even and within threshold
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int j = i;
                // Extend the subarray while conditions are satisfied
                while (j < n - 1 && 
                       nums[j] % 2 != nums[j + 1] % 2 &&  // alternating parity
                       nums[j + 1] <= threshold) {         // within threshold
                    j++;
                }
                // Update max length
                maxLen = max(maxLen, j - i + 1);
            }
        }
        
        return maxLen;
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