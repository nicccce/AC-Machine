#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int ans =0 ;
    for(int i = 0; i + 4 < s.length(); i++){
        if(s.substr(i, 5) == "edgnb") ans++;
    }
    cout << ans << endl;


	return 0;
}