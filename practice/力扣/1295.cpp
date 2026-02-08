// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        
        for (int num : nums) {
            int digits = 0;
            int temp = num;
            
            // Count the number of digits in the current number
            while (temp > 0) {
                digits++;
                temp /= 10;
            }
            
            // Check if the number of digits is even
            if (digits % 2 == 0) {
                count++;
            }
        }
        
        return count;
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