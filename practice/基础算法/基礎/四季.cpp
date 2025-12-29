#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string date;
        cin>>date;
        int month=stoi(date.substr(5,2));
        if(month>=3&&month<=5)cout<<"spring";
        else if(month>=6&&month<=8)cout<<"summer";
        else if(month>=9&&month<=11)cout<<"autumn";
        else cout<<"winter";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}