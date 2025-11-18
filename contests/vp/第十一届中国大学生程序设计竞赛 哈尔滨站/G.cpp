// https://qoj.ac/contest/2575/problem/14814

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> h(n+1, vector<int>(m+1));

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> h[i][j];

        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(h[i][j]<0 && j>=2){
                    h[i][j-1] -= abs(h[i][j]);
                    h[i][j] = 0;
                }
                else if(h[i][j]>0 && i+1<=n){
                    h[i+1][j] += h[i][j];
                    h[i][j] = 0;
                }
            }
        }

        int summ = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                summ += abs(h[i][j]);

        cout << summ << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}