#include<bits/stdc++.h>
using namespace std;
#define int long long
     int qpow(int b, int p, int mod)
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
     int inv(int x, int mod)
    {
        return qpow(x, mod - 2, mod);
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
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,n;
        cin>>a>>b>>n;
        int x=1,y=1;
        int nn=(n%b==0?b:n%b);
        ex_gcd(a,b,x,y);
        int z=-((nn)*y%a);
        if(z<0)z+=a;
        if(z*b+(nn)>=n){
            cout<<"Yes\n";
            return;
        }cout<<"No\n";

    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}