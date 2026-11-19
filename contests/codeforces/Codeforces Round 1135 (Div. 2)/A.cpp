#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<"\n";
        }
        else{
            for(int i=1;i<=n;i++){
                cout<<(i%2==1?i+1:i-1)<<' ';
            }
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}
