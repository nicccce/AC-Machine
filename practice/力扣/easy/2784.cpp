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
                                                                                                                                                                             


/*
 * @lc app=leetcode.cn id=2784 lang=cpp
 *
 * [2784] 检查数组是否是好的
 */

// @lc code=start
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // 检查长度是否符合要求
        if (n != maxVal + 1) {
            return false;
        }
        
        // 检查元素是否符合要求
        vector<int> cnt(maxVal + 1, 0);
        for (int num : nums) {
            cnt[num]++;
        }
        
        // 检查1到maxVal-1的元素是否都只出现1次，maxVal是否出现2次
        for (int i = 1; i < maxVal; i++) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        if (cnt[maxVal] != 2) {
            return false;
        }
        
        return true;
    }
};
// @lc code=end