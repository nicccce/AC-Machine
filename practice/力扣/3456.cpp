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
 * @lc app=leetcode.cn id=3456 lang=cpp
 *
 * [3456] 找出长度为 K 的特殊子字符串
 */

// @lc code=start
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i <= n - k; i++) {
            // 检查长度为k的子串是否只包含一个唯一字符
            char c = s[i];
            bool allSame = true;
            
            for (int j = i; j < i + k; j++) {
                if (s[j] != c) {
                    allSame = false;
                    break;
                }
            }
            
            if (allSame) {
                // 检查前后字符是否不同
                bool valid = true;
                
                // 检查前面的字符
                if (i > 0 && s[i - 1] == c) {
                    valid = false;
                }
                
                // 检查后面的字符
                if (i + k < n && s[i + k] == c) {
                    valid = false;
                }
                
                if (valid) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end