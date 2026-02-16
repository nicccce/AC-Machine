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
    int calc(vector<int>& p) {
        int s = 0;
        for (int i = 0; i < p.size(); ++i) {
            int mult = 1;
            if (i >= 1 && p[i-1] == 10) mult = 2;
            else if (i >= 2 && p[i-2] == 10) mult = 2;
            s += p[i] * mult;
        }
        return s;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = calc(player1);
        int s2 = calc(player2);
        if (s1 > s2) return 1;
        if (s2 > s1) return 2;
        return 0;
    }
};
