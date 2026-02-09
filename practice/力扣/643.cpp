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

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        // Calculate sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        // Use sliding window technique
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        
        return (double)maxSum / k;
    }
};