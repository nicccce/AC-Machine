// https://leetcode.cn/problems/longest-valid-parentheses/?envType=problem-list-v2&envId=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),ans=0;
        vector<int> dp(n+2),pr(n+2,-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                dp[i+1]=0;
                pr[i+1]=i;
            }else{
                if(pr[i]==-1){
                    dp[i+1]=0;
                    pr[i+1]=-1;
                }else{
                    dp[i+1]=dp[i]+1+dp[pr[i]];
                    pr[i+1]=pr[pr[i]];
                }
            }ans=max(ans,dp[i+1]);
        }
        return ans*2;
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
