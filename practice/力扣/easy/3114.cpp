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
    string findLatestTime(string s) {
        string result = s;
        
        // Handle hours first
        // If both hour digits are '?', use "11" for maximum
        if (result[0] == '?' && result[1] == '?') {
            result[0] = '1';
            result[1] = '1';
        }
        // If only first hour digit is '?'
        else if (result[0] == '?') {
            if (result[1] <= '1') {
                result[0] = '1';
            } else {
                result[0] = '0';
            }
        }
        // If only second hour digit is '?'
        else if (result[1] == '?') {
            if (result[0] == '1') {
                result[1] = '1';
            } else {
                result[1] = '9';
            }
        }
        
        // Handle minutes
        // If both minute digits are '?', use "59" for maximum
        if (result[3] == '?' && result[4] == '?') {
            result[3] = '5';
            result[4] = '9';
        }
        // If only first minute digit is '?'
        else if (result[3] == '?') {
            result[3] = '5';  // Max possible is 5
        }
        // If only second minute digit is '?'
        else if (result[4] == '?') {
            result[4] = '9';  // Max possible is 9
        }
        
        return result;
    }
};