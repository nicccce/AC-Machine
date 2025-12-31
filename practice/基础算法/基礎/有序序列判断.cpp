#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int gcnt,lcnt;
        gcnt=lcnt=0;
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) gcnt++;
            else if(a[i]<a[i-1]) lcnt++;
        }
        if(gcnt*lcnt==0)cout<<"sorted";
        else cout<<"unsorted";  
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}