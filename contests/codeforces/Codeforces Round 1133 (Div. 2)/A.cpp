#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,k;cin>>n>>k;
        int jia=0,jib=0;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x%2)jia++;
        }
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x%2)jib++;
        }
        if(k%2==0){
            if(jia>=jib){
                cout<<"yes\n";
                return;
            }
        }else{
            if(jia<=jib){
                cout<<"yes\n";
                return;
            }
        }
        cout<<"no\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}