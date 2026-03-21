#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int x,y,k;
        cin>>x>>y>>k;
        if(y==1){
            cout<<-1<<'\n';
            return;
        }
        int now=k-1;
        for(int i=0;i<x;i++){
            now+=now/(y-1);
            if(now+1>1e12){
                cout<<-1<<'\n';
                return;
            }
        }
        cout<<now+1<<'\n';;
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
