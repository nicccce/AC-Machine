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
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        // To get maximum value, replace first non-9 digit with 9
        string maxStr = s;
        char firstNonNine = ' ';
        for (char c : s) {
            if (c != '9') {
                firstNonNine = c;
                break;
            }
        }
        if (firstNonNine != ' ') {
            for (int i = 0; i < maxStr.length(); i++) {
                if (maxStr[i] == firstNonNine) {
                    maxStr[i] = '9';
                }
            }
        }
        
        // To get minimum value, replace first non-0 digit with 0
        // But we want the first digit to not be 0 (to avoid leading zeros effect on value)
        string minStr = s;
        char firstNonZero = minStr[0];  // Replace the first digit with 0 to get minimum
        for (int i = 0; i < minStr.length(); i++) {
            if (minStr[i] == firstNonZero) {
                minStr[i] = '0';
            }
        }
        
        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);
        
        return maxVal - minVal;
    }
};