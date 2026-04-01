#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int n,m;cin>>n>>m;
        string a,s;cin>>a>>s;
        int p=0;
        for(char c:s){
            if(c=='L')p=max(0LL,p-1);
            else if(c=='R')p=min(n-1,p+1);
            else if(c=='U')a[p]=(a[p]-'0'+1)%10+'0';
            else if(c=='D')a[p]=(a[p]-'0'+9)%10+'0';
        }
        cout<<a<<"\n";
    };
    int t;cin>>t;
    while(t--)solve();
}