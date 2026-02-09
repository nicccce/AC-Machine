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
    int maximumPopulation(vector<vector<int>>& logs) {
        int cnt[101] = {0};
        for (auto &l : logs) {
            for (int y = l[0]; y < l[1]; ++y) {
                cnt[y - 1950]++;
            }
        }
        int maxCnt = 0, year = 1950;
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                year = 1950 + i;
            }
        }
        return year;
    }
};
