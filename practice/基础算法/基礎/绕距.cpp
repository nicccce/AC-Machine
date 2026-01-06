#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        printf("%.7f",abs(sqrt(pow(x1-x2,2)+pow(y1-y2,2))-abs(x1-x2)-abs(y1-y2)));
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}