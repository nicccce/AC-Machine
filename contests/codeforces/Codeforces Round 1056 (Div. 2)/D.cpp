// https://codeforces.com/contest/2152/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        map<pair<int,int>,bool> mp;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<n;j++){
                cout<<i<<' '<<j<<endl;
                int an;
                cin>>an;
                if(an==1){
                    return;
                }else{
                    for(int x=1;x<=n;x++){
                    for(int y=x+1;y<=n;y++){
                        if(x!=i&&x!=j&&y!=i&&y!=j){
                            if(mp[{i,x}]==1&&mp[{j,y}]==1){
                                cout<<x<<' '<<y;
                                cin>>an;
                            }if(mp[{i,y}]==1&&mp[{j,x}]==1){
                                cout<<x<<' '<<y;
                                cin>>an;
                            }if(mp[{i,x}]==1&&mp[{x,y}]==1){
                                cout<<j<<' '<<y;
                                cin>>an;
                            }if(mp[{i,y}]==1&&mp[{x,y}]==1){
                                cout<<j<<' '<<x;
                                cin>>an;
                            }if(mp[{j,x}]==1&&mp[{x,y}]==1){
                                cout<<i<<' '<<y;
                                cin>>an;
                            }if(mp[{j,y}]==1&&mp[{x,y}]==1){
                                cout<<i<<' '<<x;
                                cin>>an;
                            }
                        }
                    }
                    }
                }
                
            }
        }
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}