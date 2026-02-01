// https://leetcode.cn/problems/wildcard-matching/?envType=problem-list-v2&envId=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<bool> dp(n+1);
        dp[0]=1;
        for(int j=0;j<m;j++){
            if(p[j]=='?'){
                for(int i=n-1;i>=0;i--){
                    dp[i+1]=dp[i];
                }dp[0]=0;
            }else if(p[j]=='*'){
                for(int i=0;i<n;i++){
                    dp[i+1]=max(dp[i],dp[i+1]);
                }
            }else{
                for(int i=n-1;i>=0;i--){
                    if(s[i]==p[j])
                    dp[i+1]=dp[i];
                    else dp[i+1]=0;
                }dp[0]=0;
            }
        }return dp[n];
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
