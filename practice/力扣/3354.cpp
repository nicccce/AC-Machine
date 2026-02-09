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

bool check(vector<int> nums, int start, int dir) {
    int n = nums.size();
    int curr = start;
    int d = dir;
    while (curr >= 0 && curr < n) {
        if (nums[curr] == 0) {
            curr += d;
        } else {
            nums[curr]--;
            d = -d;
            curr += d;
        }
    }
    for (int x : nums) if (x != 0) return false;
    return true;
}

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (check(nums, i, -1)) cnt++;
                if (check(nums, i, 1)) cnt++;
            }
        }
        return cnt;
    }
};
