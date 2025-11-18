// https://codeforces.com/contests/2163/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&]() {
        int n,ans=0;
        cin >> n;
        vector<int> a1(n+1),a2(n+1);
        for(int i=1;i<=n;i++)cin>>a1[i];
        for(int i=1;i<=n;i++)cin>>a2[i];
        vector<int> minprefix(n+1),maxprefix(n+1);
        minprefix[1]=a1[1],maxprefix[1]=a1[1];
        for(int i=2; i<=n; i++)
            minprefix[i]=min(minprefix[i-1],a1[i]),maxprefix[i]=max(maxprefix[i-1],a1[i]);
        vector<int> suf_mi(n+1),suf_mx(n+1);
        suf_mi[n]=a2[n],suf_mx[n]=a2[n];
        for(int i=n-1; i>=1; i--)
            suf_mi[i]=min(suf_mi[i+1],a2[i]),suf_mx[i]=max(suf_mx[i+1],a2[i]);
        vector<int> suf_mi2(2*n+5, LLONG_MAX);
        for(int i=1; i<=n; i++){
            int tmpMi = min(minprefix[i], suf_mi[i]),tmpMx = max(maxprefix[i], suf_mx[i]);
            if(suf_mi2[tmpMi] > tmpMx)suf_mi2[tmpMi] = tmpMx;
        }
        for(int i=2*n; i>=1; i--)suf_mi2[i]=min(suf_mi2[i], suf_mi2[i+1]);
        for(int l=1; l<=2*n; l++)ans+=max(2*n-suf_mi2[l]+1, 0LL);
        cout << ans << '\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}