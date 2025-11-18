// https://codeforces.com/contest/2161/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
class _Math
{
public:
    static int qpow(int b, int p)
    {
        int r = 1;
        while (p)
        {
            if (p & 1)
                r = r * b % mod;
            b = b * b % mod, p >>= 1;
        }
        return r;
    }
    static int inv(int x)
    {
        return qpow(x, mod - 2);
    }
    vector<int> pri;
    vector<int> phi;
    void Prime_pre(int n)
    {
        phi = vector<int>(n + 1);
        vector<bool> not_prime(n + 1, 0);
        phi[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!not_prime[i])
            {
                pri.push_back(i);
                phi[i] = i - 1;
            }
            for (int pri_j : pri)
            {
                if (i * pri_j > n)
                    break;
                not_prime[i * pri_j] = true;
                if (i % pri_j == 0)
                {
                    phi[i * pri_j] = phi[i] * pri_j;
                    break;
                }
                phi[i * pri_j] = phi[i] * phi[pri_j];
            }
        }
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
    // int log_2(int x)
    // {
    //     return __bit_width(x) - 1;
    // }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<int> dd;
        int rep=1,ans=0;
        if(n==1){
            cout<<0<<'\n';
            return;
        }
        int pp=-1,ppp=1;
        vector<int> ppdp;
        for(int x=2;x<=n;x++){
            if(a[x]==a[x-1]+1){
                dd.push_back(rep);
                rep=1;
            }
            else if(a[x]==a[x-1])rep++;
            else {
                if(dd.size()==0){
                    rep=1;
                    ppp=x;
                    continue;
                }
                dd.push_back(rep);
                int nn=dd.size();
                vector<vector<int>> dp(nn,vector<int>(2,0));
                dp[0][1]=dd[0];
                if(pp!=-1&&a[pp]==a[ppp]+1){
                    dp[0][1]=ppdp[1];
                    dp[0][0]=min(ppdp[0],ppdp[1]);
                }{
                for(int i=1;i<nn;i++){
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=min(dp[i-1][1],dp[i-1][0])+dd[i];
                }
                ans+=min(dp[nn-1][0],dp[nn-1][1]);
                ppdp=dp[nn-1];
            }
                pp=x-1;
                ppp=x;
                dd.clear();
                rep=1;
            }
        }
        if(dd.size()!=0){
                dd.push_back(rep);
                int nn=dd.size();
                vector<vector<int>> dp(nn,vector<int>(2,0));
                dp[0][1]=dd[0];
                for(int i=1;i<nn;i++){
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=min(dp[i-1][1],dp[i-1][0])+dd[i];
                }
                ans+=min(dp[nn-1][0],dp[nn-1][1]);
            }
            
        cout<<ans<<'\n';

    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}