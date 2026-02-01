// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/?envType=problem-list-v2&envId=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,0);
        for(int x=0;x<k;x++){
            int mi=1000000;
            for(int i=0;i<n;i++){
                int tmp=dp[i+1];
                dp[i+1]=max(dp[i],prices[i]-mi);
                mi=min(prices[i]-tmp,mi);
            }
        }
        return dp[n];
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
