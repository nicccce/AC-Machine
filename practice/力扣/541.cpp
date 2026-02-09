// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            // 计算需要反转的长度
            int left = i;
            int right = min(i + k - 1, n - 1);
            
            // 反转前k个字符（或剩余所有字符）
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
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