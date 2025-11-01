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
        vector<vector<int>> a(n+2,vector<int>(n+2));
        int summ=0,fx=0,fy=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                char c;
                cin>>c;
                if(c=='#'){
                    a[i][j]=1;
                    fx=i,fy=j;
                    summ++;
                }
            }
        }
        // cout<<summ;
        if(summ==0||summ==1){
            cout<<"Yes\n";
            return;
        }
        if(a[fx+1][fy]+a[fx][fy+1]+a[fx+1][fy+1]+1==summ||a[fx+1][fy]+a[fx][fy-1]+a[fx+1][fy-1]+1==summ||a[fx-1][fy]+a[fx][fy+1]+a[fx-1][fy+1]+1==summ||a[fx-1][fy]+a[fx][fy-1]+a[fx-1][fy-1]+1==summ){
            cout<<"Yes\n";
            return;
        }
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        for(int i=1;i<=n;i++){
            if(fx+fy-i>=1&&fx+fy-i<=n)
            cnt1+=a[i][fx+fy-i];
            if(fx+fy+1-i>=1&&fx+fy+1-i<=n)
            cnt1+=a[i][fx+fy+1-i];
            
            if(fx+fy-i>=1&&fx+fy-i<=n)
            cnt2+=a[i][fx+fy-i];
            if(fx+fy-1-i>=1&&fx+fy-1-i<=n)
            cnt2+=a[i][fx+fy-1-i];
            
            if(-fx+fy+i>=1&&-fx+fy+i<=n)
            cnt3+=a[i][-fx+fy+i];
            if(-fx+fy-1+i>=1&&-fx+fy-1+i<=n)
            cnt3+=a[i][-fx+fy-1+i];

            if(-fx+fy+i>=1&&-fx+fy+i<=n)
            cnt4+=a[i][-fx+fy+i];
            if(-fx+fy+1+i>=1&&-fx+fy+1+i<=n)
            cnt4+=a[i][-fx+fy+1+i];
        }
        if(cnt1==summ||cnt2==summ||cnt3==summ||cnt4==summ){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}