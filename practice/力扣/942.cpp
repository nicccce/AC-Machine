// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> result;
        int low = 0, high = n;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                result.push_back(low);
                low++;
            } else {
                result.push_back(high);
                high--;
            }
        }
        
        // Add the last remaining number
        result.push_back(low);  // low and high are the same at this point
        
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