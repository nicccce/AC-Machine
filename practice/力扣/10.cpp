// https://leetcode.cn/problems/regular-expression-matching/description/?envType=problem-list-v2&envId=dynamic-programming
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
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<bool> dp(n+1,0);dp[0]=1;
        for(int j=0;j<m;j++){
            if(j==m-1||p[j+1]!='*'){                
                for(int i=n-1;i>=0;i--){
                    if(dp[i]&&(s[i]==p[j]||p[j]=='.')){
                        dp[i+1]=1;
                    }else{
                        dp[i+1]=0;
                    }
                }
                dp[0]=0;
            }else{
                for(int i=0;i<n;i++){
                    if(dp[i]&&(s[i]==p[j]||p[j]=='.')){
                        dp[i+1]=1;
                    }
                }
                j++;
            }
            for(int i=0;i<=n;i++){
                cout<<dp[i];
            }cout<<'\n';
        }
        return dp[n];
    }
};