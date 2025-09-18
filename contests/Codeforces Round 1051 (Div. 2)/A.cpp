https://codeforces.com/contest/2143/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n),ind(n+1);
        for(int i=0;i<n;i++){cin>>a[i];ind[a[i]]=i;}
        int l=ind[n],r=ind[n];
        for(int i=n-1;i>=1;i--){
            if(ind[i]==l-1)l=ind[i];
            else if(ind[i]==r+1)r=ind[i];
            else{cout<<"No\n";return;}
        }
        cout<<"Yes\n";

    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}