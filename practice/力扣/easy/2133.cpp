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
 * @lc app=leetcode.cn id=2133 lang=cpp
 *
 * [2133] 检查是否每一行每一列都包含全部整数
 */

// @lc code=start
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            set<int> rowSet, colSet;
            for (int j = 0; j < n; j++) {
                rowSet.insert(matrix[i][j]);
                colSet.insert(matrix[j][i]);
            }
            if (rowSet.size() != n || colSet.size() != n) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end