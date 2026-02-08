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
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */

// @lc code=start
class Solution {
public:
    string winningPlayer(int x, int y) {
        // 每次操作需要拿走总价值为115的硬币
        // 一种方式是拿1个75的和4个10的硬币(75 + 4*10 = 115)
        // 另一种方式是拿11个10的硬币(11*10 = 110 ≠ 115, 所以不行)
        // 实际上，只有75 + 4*10 = 115这一种方式
        
        // 所以问题转化为：最多能进行多少次操作
        // 每次操作消耗1个价值为75的硬币和4个价值为10的硬币
        // 最多能操作 min(x, y / 4) 轮
        
        int rounds = min(x, y / 4);
        
        // 如果操作轮数是奇数，则Alice赢(因为Alice先手)
        // 如果操作轮数是偶数，则Bob赢
        if (rounds % 2 == 1) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};
// @lc code=end