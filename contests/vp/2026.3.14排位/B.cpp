// https://codeforces.com/problemset/problem/1217/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        string s;
        cin>>s;
        int n=s.length(),ans=0;
        s.insert(s.begin(),'0');
        vector<int> a(n+1);
        vector<int> cnt0(n+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                cnt0[i]=cnt0[i-1]+1;
            }else{
                cnt0[i]=0;
            }
        }
        for(int i=1;i<=20;i++){
            for(int j=n;j>=i;j--){
                int tmp=a[j];
                a[j]=(a[j-1]<<1)+(s[j]-'0');
                if(a[j]!=tmp&&a[j]>=i&&a[j]<=i+cnt0[j-i])ans++;
            }
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}