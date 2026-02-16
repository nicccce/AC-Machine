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
    bool canMakeSquare(vector<vector<char>>& grid) {
        // Check all possible 2x2 sub-squares in the 3x3 grid
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                // Count same and different colors in current 2x2 square
                int sameCount = 0;
                int total = 4;
                
                if (grid[i][j] == grid[i][j+1]) sameCount++;
                if (grid[i][j] == grid[i+1][j]) sameCount++;
                if (grid[i][j] == grid[i+1][j+1]) sameCount++;
                if (grid[i][j+1] == grid[i+1][j]) sameCount++;
                if (grid[i][j+1] == grid[i+1][j+1]) sameCount++;
                if (grid[i+1][j] == grid[i+1][j+1]) sameCount++;
                
                // If 3 or more cells of the same color exist, we can make a square with one change
                if (sameCount >= 3) {
                    return true;
                }
            }
        }
        
        return false;
    }
};