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
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, INT_MAX);
        for (string w : words) {
            vector<int> cur(26, 0);
            for (char c : w) cur[c - 'a']++;
            for (int i = 0; i < 26; i++) cnt[i] = min(cnt[i], cur[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
