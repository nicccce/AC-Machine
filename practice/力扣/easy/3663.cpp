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
    int getLeastFrequentDigit(int n) {
        vector<int> count(10, 0);
        
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        
        int minFreq = INT_MAX;
        int result = 9;
        
        for (int i = 9; i >= 0; i--) {
            if (count[i] > 0 && count[i] <= minFreq) {
                minFreq = count[i];
                result = i;
            }
        }
        
        return result;
    }
};