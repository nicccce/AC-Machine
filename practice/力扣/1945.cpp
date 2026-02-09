// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char c : s) {
            num += to_string(c - 'a' + 1);
        }
        
        int sum = 0;
        for(char c : num) {
            sum += c - '0';
        }
        k--;
        
        while(k--) {
            num = to_string(sum);
            sum = 0;
            for(char c : num) {
                sum += c - '0';
            }
        }
        
        return sum;
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