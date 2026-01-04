#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        cin>>s;
        int cntA=0,cntB=0;
        s.pop_back();
        for(auto c:s) {
            if(c=='A')   cntA++;
            else         cntB++;
        }
        if(cntA>cntB)   cout<<"A\n";
        else if(cntB>cntA)   cout<<"B\n";
        else                cout<<"E\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}