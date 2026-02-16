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
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int x = nums[i], y = nums[j];
            int digits = 0;
            while (y) {
                digits++;
                y /= 10;
            }
            long long concat = (long long)x * pow(10, digits) + nums[j];
            ans += concat;
            i++; j--;
        }
        if (i == j) ans += nums[i];
        return ans;
    }
};
