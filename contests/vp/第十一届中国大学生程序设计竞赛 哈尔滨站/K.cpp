// https://qoj.ac/contest/2575/problem/14824

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n;
        cin >> n;
        cout << n << "\n";
        for(int i=1; i<=n; i++)
            cout << i << " ";
        cout << "\n";
        cout << n << " ";
        for(int i=2; i<=n; i++)
            cout << i*n-(n-i+1) << " ";
        cout << "\n";
    };

    solve();

    return 0;
}