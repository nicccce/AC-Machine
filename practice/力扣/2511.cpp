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
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (forts[i] == 1) {
                int j = i + 1;
                while (j < n && forts[j] == 0) j++;
                if (j < n && forts[j] == -1) {
                    ans = max(ans, j - i - 1);
                }
            } else if (forts[i] == -1) {
                int j = i + 1;
                while (j < n && forts[j] == 0) j++;
                if (j < n && forts[j] == 1) {
                    ans = max(ans, j - i - 1);
                }
            }
        }
        return ans;
    }
};
