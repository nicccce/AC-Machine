#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<string> a(n);
        vector<int> pos(n);
        vector<vector<char>> ans(n,vector<char>(n,'0'));
        for(int i=0;i<n;i++){
            cin>>a[i];
            for(int j=0;j<n;j++){
                if(a[i][j]!='.'){
                    pos[i]=j;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=i;j>=0;j--){
                ans[j][pos[i]]=a[i][pos[i]];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                for(int x=pos[i]-1;x>=0;x--){
                    if(ans[j][x]!='0'){
                        break;
                    }else{
                        ans[j][x]=a[i][pos[i]];
                    }
                }
            }
            if(ans[i][n-1]=='0'){
                int p;
                for(p=n-1;p>=0;p--){
                    if(ans[i][p]!='0')break;
                }

            }
        }
        for(int i=0;i<n;i++){
            if(ans[i][n-1]=='0'){
                int p;
                for(p=n-1;p>=0;p--){
                    if(ans[i][p]!='0')break;
                }
                for(int j=n-1;j>=0;j--){
                    if(ans[i][j]!='0')break;
                    ans[i][j]=ans[i][p];
                }
                
            }
            for(int j=0;j<n;j++){
                cout<<(ans[i][j]=='0'?ans[i][j]:ans[i][j]);
            }cout<<'\n';
        }
    };
    int t;
    // for (cin >> t; t; t--) 
    solve();
    return 0;
}