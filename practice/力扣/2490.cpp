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
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        
        // 检查每个空格前后的字符是否相同
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i-1] != sentence[i+1]) {
                    return false;
                }
            }
        }
        
        // 检查最后一个字符是否等于第一个字符
        return sentence[0] == sentence[n-1];
    }
};