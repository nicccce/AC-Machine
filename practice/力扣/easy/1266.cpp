// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;
        
        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];
            
            // The minimum time to travel between two points is the maximum
            // of the absolute differences in x and y coordinates
            // This is because we can move diagonally
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            
            total_time += max(dx, dy);
        }
        
        return total_time;
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