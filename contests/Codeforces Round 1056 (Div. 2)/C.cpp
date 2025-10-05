// https://codeforces.com/contest/2152/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=2e5,mod=676767677;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        bool flg=0;
        for(int i=0;i<n;i++){cin>>a[i];if(i>0&&a[i]!=a[i-1])flg=1;}
        if(flg==0){
            if(n%2==0&&(a[0]==n/2+1||a[0]==n/2)){
                cout<<1<<'\n';
                return;
            }
            if(n%2==1&&a[0]==n/2+1){
                cout<<2<<'\n';
                return;
            }
            cout<<0<<'\n';
            return;
        }
        vector<int> f(n,2),prefix(n),subfix(n);
        for(int i=1;i<n;i++){
            // cout<<a[i-1]<<a[i]<<f[i-1]<<'\n';
            if(a[i]==a[i-1]+1){
                if(f[i-1]==1){
                    cout<<0<<'\n';
                    return;
                }
                f[i]=0;
                if(f[i-1]==2){
                    int j=i-2;
                    f[i-1]=0;
                    while (j>=0&&f[j]==2)
                    {
                        f[j]=!f[j+1];
                        j--;
                    }
                }
            }else if(a[i]+1==a[i-1]){
                if(f[i-1]==0){
                    cout<<0<<'\n';
                    return;
                }
                f[i]=1;
                if(f[i-1]==2){
                    int j=i-2;
                    f[i-1]=1;
                    while (j>=0&&f[j]==2)
                    {
                        f[j]=!f[j+1];
                        j--;
                    }
                }
            }else if(a[i]==a[i-1]){
                if(f[i-1]==2)f[i]=2;
                else 
                f[i] = !f[i-1];
            }else{
                cout<<0<<'\n';
                return;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<f[i]<<' ';
        // }
        // cout<<'\n';
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(f[i-1]==0);
        }for(int i=n-2;i>=0;i--){
            subfix[i]=subfix[i+1]+(f[i+1]==1);
        }
        for(int i=0;i<n;i++){
            if(a[i]!=prefix[i]+subfix[i]+1){
                cout<<0<<'\n';
                return;
            }
        }
        cout<<1<<'\n';
    };
    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}