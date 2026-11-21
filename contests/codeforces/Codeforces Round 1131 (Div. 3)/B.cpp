#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int x,y,z;
        cin>>x>>y>>z;
        vector<pair<int,char>> a={{x,'R'},{y,'S'},{z,'P'}};
        sort(a.begin(),a.end());
        array<char,2> s={a[1].second,a[2].second};
        sort(s.begin(),s.end());
        for(int i=0;i<x+y+z;i++){
            if(s==array<char,2>{'P','R'})cout<<'P';
            if(s==array<char,2>{'R','S'})cout<<'R';
            if(s==array<char,2>{'P','S'})cout<<'S';
        }cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}