#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int pcnt=0,ncnt=0;
        for(int i=0;i<10;i++) {
            int c;
            cin>>c;
            if(c>0) pcnt++;
            else if(c<0) ncnt++;
        }
        cout<<"positive:"<<pcnt<<"\nnegative:"<<ncnt<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}