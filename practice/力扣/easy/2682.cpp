#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n + 1, false);
        int current = 1;
        int step = 1;
        
        while (!visited[current]) {
            visited[current] = true;
            current = (current + step * k) % n;
            if (current == 0) current = n;
            step++;
        }
        
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                result.push_back(i);
            }
        }
        
        return result;
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