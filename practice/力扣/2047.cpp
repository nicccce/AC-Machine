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
    int countValidWords(string sentence) {
        int count = 0;
        stringstream ss(sentence);
        string token;
        
        while (ss >> token) {
            if (isValidToken(token)) {
                count++;
            }
        }
        
        return count;
    }
    
    bool isValidToken(string token) {
        int hyphenCount = 0;
        int n = token.length();
        
        for (int i = 0; i < n; i++) {
            char c = token[i];
            
            if (isdigit(c)) {
                return false;
            }
            
            if (c == '-') {
                hyphenCount++;
                if (hyphenCount > 1) return false;
                if (i == 0 || i == n-1) return false;
                if (!islower(token[i-1]) || !islower(token[i+1])) return false;
            }
            
            if (c == '!' || c == '.' || c == ',') {
                if (i != n-1) return false;
            }
        }
        
        return true;
    }
};