// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;  // At least one element will always satisfy the condition
        
        // For each starting position
        for (int i = 0; i < n; i++) {
            int currentGCD = nums[i];
            int currentLCM = nums[i];
            long long currentProd = nums[i];
            
            if (currentProd == (long long)currentGCD * currentLCM) {
                maxLen = max(maxLen, 1);
            }
            
            // Extend from this position
            for (int j = i + 1; j < n; j++) {
                // Update GCD
                currentGCD = __gcd(currentGCD, nums[j]);
                
                // Update LCM - need to be careful about overflow
                long long newLCM = (long long)currentLCM / __gcd(currentLCM, nums[j]) * nums[j];
                
                // Check for potential overflow before updating
                if (newLCM > 1e10) {  // If LCM is too large, it won't satisfy the condition with reasonable products
                    break;
                }
                
                currentLCM = (int)newLCM;
                
                // Update product - also check for overflow
                if (currentProd > 1e10 / nums[j]) {  // If multiplying would cause overflow
                    break;
                }
                currentProd *= nums[j];
                
                // Check if the condition is satisfied
                if (currentProd == (long long)currentGCD * currentLCM) {
                    maxLen = max(maxLen, j - i + 1);
                } else if (currentProd > (long long)currentGCD * currentLCM) {
                    // If product is already larger than lcm*gcd, no need to extend further
                    break;
                }
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