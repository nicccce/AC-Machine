#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowels = 0, consonants = 0;
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (vowelSet.count(c)) {
                    vowels++;
                } else {
                    consonants++;
                }
            }
        }
        
        if (consonants == 0) {
            return 0;
        }
        
        return vowels / consonants;
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