// https://codeforces.com/contest/2151/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
int a[N*2+1],s[N*2+1],m[N*2+1];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,m,x;
        string s;
        cin>>n>>m>>s;
        map<int,int> mp;
        int k=1;
        while (m--)
        {
            cin>>x;
            mp[x]=1;
        }
        
        for(int i=0,x;i<n;i++)
        {
            k++;
            if(s[i]=='A')mp[k]=1;
            else
            {
                while(mp.count(k)) k++;
                mp[k]=1;
                while(mp.count(k)) k++;
            }
        }
        cout<<mp.size()<<'\n';
        for(auto [x,c]:mp)
            if(c)cout<<x<<" ";
        cout<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}