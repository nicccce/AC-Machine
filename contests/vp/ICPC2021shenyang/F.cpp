#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

unordered_map<char, char> mp;

vector<string> vc;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string str;
    cin >> str;
    
    
    string ans = "";
    for(int i = 1; i <= n; i++){
        string s = str.substr(0, i);
        mp.clear();
        int cnt = 0;
        for(int j = s.length() - 1; j >= 0; j--){
            if(mp[s[j]]) continue;
            mp[s[j]] = 'a' + cnt;
            cnt++;
        }
        string now ;
        for(auto it : s) now += mp[it];

        if(now > ans) ans = now;
    }
    cout << ans << endl;

	return 0;
}