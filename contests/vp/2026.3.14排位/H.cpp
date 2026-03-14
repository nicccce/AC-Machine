// https://codeforces.com/problemset/problem/621/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
    auto solve=[&](){
        int n,b,k,x;
        cin>>n>>b>>k>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]%=x;
        }
        vector<int> m(x),ans(x);
        ans[0]=1;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        // for(int i=0;i<x;i++){
        //     cout<<m[i]<<' ';
        // }
        int mod10=1;
        int tmpmod10;
        int a10=10;
        while (b)
        {
            if(b&1){
                mod10=(mod10*a10)%x;
                vector<int> tmp(x);
                for(int i=0;i<x;i++){
                    for(int j=0;j<x;j++){
                        tmp[(i*a10%x+j)%x]=(tmp[(i*a10%x+j)%x]+ans[i]*m[j]%mod)%mod;
                        // if(i==0&&j==5){
                        //     cout<<ans[i]<<' '<<m[j]<<' '<<mod10<<' '<<tmp[5]<<' ';
                        // }
                    }
                }
                for(int i=0;i<x;i++){
                    ans[i]=tmp[i];
                }
                // tmpmod10=mod10;
            }
            vector<int> tmp(x);
            // for(int i=0;i<x;i++){
            //     cout<<m[i]<<' ';
            // }cout<<"\n";
            for(int i=0;i<x;i++){
                for(int j=0;j<x;j++){
                    tmp[(i*a10%x+j)%x]=(tmp[(i*a10%x+j)%x]+m[i]*m[j]%mod)%mod;
                }
            }
            a10=(a10*a10)%x;
            for(int i=0;i<x;i++){
                m[i]=tmp[i];
            }
            b>>=1;
        }
        cout<<ans[k];
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}