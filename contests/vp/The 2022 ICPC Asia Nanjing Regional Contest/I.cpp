// https://codeforces.com/gym/104128/problem/I
#include <bits/stdc++.h>
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        string s;
        cin >> s;
        int sz = s.size();
        map<char, int> mp;
        int ans = 0;
        for(int i=0; i<sz; i++){
            mp[s[i]]++;
            ans = max(ans, mp[s[i]]);
        }
        cout << sz-ans << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}