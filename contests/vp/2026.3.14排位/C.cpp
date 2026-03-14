// https://codeforces.com/problemset/problem/1270/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n;
        cin>>n;
        vector<int> a0(n+1),a1(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a0[i]=x-i;
            a1[i]=x-(n-i);
        }
        int mi=a0[1],mip=1;
        int l=-1,r=-1;
        for(int i=2;i<=n;i++){
            if(a0[i]>mi){
                l=mip,r=i;
                goto shuchu;
            }else{
                mi=a0[i],mip=i;
            }
        }
        mi=a1[n],mip=n;
        for(int i=n-1;i>0;i--){
            if(a1[i]>mi){
                l=i,r=mip;
                goto shuchu;
            }else{
                mi=a1[i],mip=i;
            }
        }
        shuchu:
        if(l<0){
            cout<<"NO\n";
            return;
        }else{
            cout<<"YES\n";
        }cout<<l<<' '<<r<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}