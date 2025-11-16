//https://codeforces.com/contest/2169/problem/D2
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
        int x,y,k; cin>>x>>y>>k;
		if(y==1) {
			cout<<-1<<"\n";
			return;
		}
		int ans=k;
		int rem=x;
		while(rem>0&&ans<=1e12) {
			int g=(ans-1)/(y-1);
			if(g==0) break;
			int top=(g+1)*(y-1)-ans+1;
			int need=(top+g-1)/g;
			ans+=min(rem,need)*g;
			rem-=min(rem,need);
		}
		cout<<(ans<=1e12? ans:-1)<<"\n";
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}
