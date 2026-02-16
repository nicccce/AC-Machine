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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        // 按分数降序排序索引
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        
        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                result[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                result[indices[i]] = "Bronze Medal";
            } else {
                result[indices[i]] = to_string(i + 1);
            }
        }
        
        return result;
    }
};