// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s == goal) {
            // If strings are equal, we need to check if there's at least one duplicate character
            // so we can swap two identical characters
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
                if (count[c - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            // Find the differences between s and goal
            vector<int> diff;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i]) {
                    diff.push_back(i);
                }
            }
            
            // There must be exactly 2 differences, and they must be swappable
            if (diff.size() == 2) {
                return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
            }
            
            return false;
        }
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