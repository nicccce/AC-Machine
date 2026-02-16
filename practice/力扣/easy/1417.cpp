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
    string reformat(string s) {
        string digits = "";
        string letters = "";
        
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                digits += c;
            } else {
                letters += c;
            }
        }
        
        int diff = abs((int)digits.length() - (int)letters.length());
        if (diff > 1) {
            return "";
        }
        
        string result = "";
        bool digitFirst = digits.length() > letters.length();
        
        int i = 0, j = 0;
        while (i < digits.length() && j < letters.length()) {
            if (digitFirst) {
                result += digits[i++];
                digitFirst = false;
            } else {
                result += letters[j++];
                digitFirst = true;
            }
        }
        
        if (i < digits.length()) {
            result += digits[i++];
        }
        if (j < letters.length()) {
            result += letters[j++];
        }
        
        return result;
    }
};