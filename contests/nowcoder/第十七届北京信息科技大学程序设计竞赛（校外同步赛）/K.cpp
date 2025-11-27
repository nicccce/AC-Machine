// https://ac.nowcoder.com/acm/contest/122913/K
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) 
            cin>>a[i];
        int low=1,high=*max_element(a.begin(),a.end())+n,ans=high;
        auto check = [&](int x0,vector<long long>& a){
            int x=x0;
            for (auto ai : a) {
                if(x>ai)x++;
                else if(x < ai)x--;
            }
            return x-x0>0;
        };
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mid, a)) {
                ans=mid;
                high=mid - 1;
            }else{
                low=mid + 1;
            }
        }
        cout << ans << '\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}