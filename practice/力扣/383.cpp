// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magCount;
        
        // Count the occurrences of each character in magazine
        for (char c : magazine) {
            magCount[c]++;
        }
        
        // Check if ransomNote can be constructed
        for (char c : ransomNote) {
            if (magCount[c] <= 0) {
                return false;  // Character not available in magazine
            }
            magCount[c]--;  // Use one occurrence of this character
        }
        
        return true;
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