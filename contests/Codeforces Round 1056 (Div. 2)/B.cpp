// https://codeforces.com/contest/2152/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,k;
        cin>>n>>k;
        if(k==n*n-1){cout<<"NO\n";return;}
        else cout<<"YES\n";
        vector<vector<char>> a(n,vector<char>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int pj=i%2?n-1-j:j;
                if(k>0){
                    a[i][pj]=i%2?'R':'L';
                    if(j==0)a[i][pj]='U';
                    k--;
                }else{
                    a[i][pj]=i%2?'L':'R';
                    if(j==n-1)a[i][pj]='D';
                    if(i==n-1&&j==n-1){
                        a[i][pj]=i%2?'R':'L';
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<a[i][j];
            cout<<'\n';
        }
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}