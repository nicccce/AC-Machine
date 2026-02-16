// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // For each team, check if any other team is stronger than it
        for (int i = 0; i < n; i++) {
            bool isLoser = false;
            
            // Check if any team j is stronger than team i
            for (int j = 0; j < n; j++) {
                if (i != j && grid[j][i] == 1) {
                    // Team j is stronger than team i, so team i is not the champion
                    isLoser = true;
                    break;
                }
            }
            
            if (!isLoser) {
                // Team i is not weaker than any other team, so it's the champion
                return i;
            }
        }
        
        // This should not happen according to the problem statement
        return -1;
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