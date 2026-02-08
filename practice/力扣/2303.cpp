// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double totalTax = 0.0;
        int prevUpper = 0;
        
        for (vector<int>& bracket : brackets) {
            int upper = bracket[0];
            int percent = bracket[1];
            
            // Calculate the taxable income in this bracket
            int taxableIncome = min(income, upper) - prevUpper;
            
            if (taxableIncome <= 0) {
                break; // No more income to tax
            }
            
            totalTax += taxableIncome * percent / 100.0;
            
            if (income <= upper) {
                break; // All income has been taxed
            }
            
            prevUpper = upper;
        }
        
        return totalTax;
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