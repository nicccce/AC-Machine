// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string greatestLetter(string s) {
        bool hasUpper[26] = {false};
        bool hasLower[26] = {false};
        
        // Mark which uppercase and lowercase letters exist in the string
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                hasUpper[c - 'A'] = true;
            } else if (c >= 'a' && c <= 'z') {
                hasLower[c - 'a'] = true;
            }
        }
        
        // Find the greatest letter that has both uppercase and lowercase forms
        for (int i = 25; i >= 0; i--) {
            if (hasUpper[i] && hasLower[i]) {
                return string(1, 'A' + i);
            }
        }
        
        return "";
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