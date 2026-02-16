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
    int maxOperations(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int score = nums[0] + nums[1];
        int operations = 1;
        
        for (int i = 2; i < nums.size(); i += 2) {
            if (i + 1 < nums.size() && nums[i] + nums[i+1] == score) {
                operations++;
            } else {
                break;
            }
        }
        
        return operations;
    }
};