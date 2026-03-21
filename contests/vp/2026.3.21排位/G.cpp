#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int n,t;
        cin>>n>>t;
        string a,b,c;
        cin>>a>>b;
        c=a;
        vector<int>s,d;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])s.push_back(i);
            else d.push_back(i);
        }
        int m=n-t;
        auto f=[&](char x,char y){
            for(char v='a';v<='z';v++){
                if(v!=x&&v!=y)return v;
            }
        };
        if(m<=s.size()){
            for(int i=m;i<s.size();i++)
                c[s[i]]=f(a[s[i]],b[s[i]]);
            for(auto v:d)
                c[v]=f(a[v],b[v]);
        }else{
            int k=m-s.size();
            if(k*2>d.size()){
                cout<<"-1\n";
                return;
            }
            for(int i=k;i<k*2;++i){
                c[d[i]]=b[d[i]];
            }
            for(int i=k*2;i<d.size();++i){
                c[d[i]]=f(a[d[i]],b[d[i]]);
            }
        }
        cout<<c<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}