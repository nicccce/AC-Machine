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
                                                                                                                                                                             


/*
 * @lc app=leetcode.cn id=3477 lang=cpp
 *
 * [3477] 水果成篮 II
 */

// @lc code=start
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplaced = 0;
        
        for (int i = 0; i < n; i++) {
            int fruit = fruits[i];
            int placed = false;
            
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruit) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                unplaced++;
            }
        }
        
        return unplaced;
    }
};
// @lc code=end