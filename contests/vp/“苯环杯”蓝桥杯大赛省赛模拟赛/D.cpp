#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int n;cin>>n;
        if(__builtin_popcountll(n)==1)cout<<"Fang\n";
        else cout<<"Ben\n";
    };
    int t;cin>>t;
    while(t--)solve();
}