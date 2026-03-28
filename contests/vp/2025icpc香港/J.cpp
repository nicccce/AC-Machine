#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, l[4];
        cin >> n >> l[1] >> l[2] >> l[3];

        int penatly = 0, rest = 0;
        vector<int> a[4];

        for(int i=1; i<=n; i++){
            int c, p;
            cin >> c >> p;
            a[c].push_back(p);
            rest += p;
        }

        for(int i=1; i<=3; i++)
            sort(a[i].begin(), a[i].end());

        int t;
        cin >> t;

        while(rest){
            penatly += rest;
            int mx=-1, mxid=-1;
            for(int i=1; i<=3; i++){
                if(rest<=l[i] && a[i].size() && mx<a[i].back()){
                    mx = a[i].back();
                    mxid = i;
                }
            }
            
            if(mx == -1) break;

            rest -= mx;
            a[mxid].pop_back();
        }

       if(rest==0 && penatly<t) cout << "YES\n";
       else cout << "NO\n";
    };

    int q;
    for(cin>>q; q--;)
        solve();
    return 0;
}