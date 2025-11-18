// https://codeforces.com/contest/2146/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,lst=0;
        string s;
        cin>>n>>s; 
        s.push_back('1');
        vector<int> ans(n+2);
        for(int i=1;i<=n+1;i++){
            if(s[i-1]=='1'){
                if(i-lst==2){
                    cout<<"No\n";
                    return;
                }
                sort(ans.begin()+lst+1,ans.begin()+i,[&](int x,int y){return x>y;});
                lst=i;
            }
            ans[i]=i;
        }
        cout<<"Yes"<<'\n';
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<' ';
        }cout<<'\n';

    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}