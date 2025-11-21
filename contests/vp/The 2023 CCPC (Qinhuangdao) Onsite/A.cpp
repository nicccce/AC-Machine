// https://codeforces.com/gym/104787/problem/A
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, k;
        cin >> n >> k;

        map<PII, bool> mp;
        int x = 1, y = 1;
        cout << x << " " << y << "\n";
        mp[{x, y}] = 1;
        for(int i = 1; i < n; i++) {
            y++;
            cout << x << " " << y << "\n";
            mp[{x, y}] = 1;
            x++;
            cout << x << " " << y << "\n";
            mp[{x, y}] = 1;
        }
        x = n, y = 1;
        cout << x << " " << y << "\n";
        mp[{x, y}] = 1;

        int cnt = 2*n;
        if(cnt == k)
            return;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!mp[{i, j}]){
                    cout << i << " " << j << "\n";
                    cnt++;
                    if(cnt == k)
                        return;
                }
            }
        }
    };

    solve();

    return 0;
}