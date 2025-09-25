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
        int n;
        cin>>n;
		for(int i=1;i<=n*2;i++)cin>>a[i],s[i]=s[i-1]+a[i],m[i]=a[i]-m[i-1];
		for(int i=1;i<=n;i++)cout<<s[n*2]-s[n*2-i+1]-s[i-1]+(m[n*2-i+1]-m[i-1])<<" ";
		cout<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}