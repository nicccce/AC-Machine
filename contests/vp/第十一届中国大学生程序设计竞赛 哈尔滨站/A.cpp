// https://qoj.ac/contest/2575/problem/14814

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];
        sort(a.begin()+1,a.begin()+n+1);
        if(a[1]==a[n]){
            cout<<"infinite\n";
            return;
        }
        int gg=a[2]-a[1];
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]==0)continue;
            gg=__gcd(gg,a[i]-a[i-1]);
        }
        cout<<gg<<' '<<gg/__gcd(gg,a[1])<<'\n';
    };
    int T;
    for(cin>>T;T;T--)
    solve();

    return 0;
}