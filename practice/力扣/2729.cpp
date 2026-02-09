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
    bool isFascinating(int n) {
        int n2 = 2 * n;
        int n3 = 3 * n;
        
        string s = to_string(n) + to_string(n2) + to_string(n3);
        
        if (s.length() != 9) return false;
        
        unordered_set<char> digits;
        for (char c : s) {
            if (c == '0' || digits.count(c)) {
                return false;
            }
            digits.insert(c);
        }
        
        return digits.size() == 9;
    }
};