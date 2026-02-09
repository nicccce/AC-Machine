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
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for (int x : arr) total += x;
        if (total % 3 != 0) return false;
        int target = total / 3;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == target) {
                cnt++;
                sum = 0;
            }
        }
        return cnt >= 3;
    }
};
