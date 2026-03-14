// https://codeforces.com/problemset/problem/1252/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cout<<n-x+1<<' ';
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}