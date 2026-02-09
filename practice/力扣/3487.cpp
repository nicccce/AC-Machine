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
    int maxSum(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        for (int num : nums) {
            uniqueNums.insert(num);
        }
        
        int sum = 0;
        for (int num : uniqueNums) {
            if (num > 0) {
                sum += num;
            }
        }
        
        // 如果没有正数，则选择最大的单个数
        if (sum == 0) {
            int maxVal = nums[0];
            for (int num : nums) {
                maxVal = max(maxVal, num);
            }
            return maxVal;
        }
        
        return sum;
    }
};