#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int result = 0;
        
        // 有8个按键(2-9)可以使用
        // 贪心策略：将出现频率最高的字符放在每个按键的前面位置
        // 由于题目中的字符都不相同，我们只需要考虑位置分配
        // 前8个字符放在各按键第一位(按1次) 
        // 接下来8个字符放在各按键第二位(按2次)
        // 再接下来8个字符放在各按键第三位(按3次)
        // 最后最多4个字符放在各按键第四位(按4次)
        
        for (int i = 0; i < n; i++) {
            // 第i个字符(按0-indexed)应该按的次数是 (i / 8) + 1
            result += (i / 8) + 1;
        }
        
        return result;
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