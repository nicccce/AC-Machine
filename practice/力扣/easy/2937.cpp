// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        
        // Find the common prefix length
        int i = 0;
        while (i < min({n1, n2, n3}) && s1[i] == s2[i] && s2[i] == s3[i]) {
            i++;
        }
        
        // If there's no common prefix, return -1
        if (i == 0) {
            return -1;
        }
        
        // Calculate the minimum operations needed
        return (n1 - i) + (n2 - i) + (n3 - i);
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