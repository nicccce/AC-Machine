// https://codeforces.com/contests/2163/problem/A
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
        string s;
        cin>>s;
        int n=s.length();
        if(s.length()==1){
            cout<<1<<'\n';
            return;
        }
        for(int i=1;i<n;i++){
            if(s[i]==60&&s[i-1]==62){
                cout<<-1<<'\n';
                return;
            }if(s[i-1]==42&&(s[i]==60||s[i]==42)||s[i]==42&&(s[i-1]==62||s[i-1]==42)){
                cout<<-1<<'\n';
                return;
            }
        }
        int ans=0,ans1=0;
        for(int i=0;i<n;i++){
            if(s[i]==60)ans++;
            if(s[i]==42)ans1++;
        }
        cout<<max(ans+ans1,n-ans)<<'\n';
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}