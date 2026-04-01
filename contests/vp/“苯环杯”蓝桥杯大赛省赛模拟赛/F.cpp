#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int n;cin>>n;
        vector<int> a(n+1),l(n+1,0),r(n+1,n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<int> s;
        for(int i=1;i<=n;i++){
            while(s.size()&&a[s.back()]<a[i])s.pop_back();
            if(s.size())l[i]=s.back();
            s.push_back(i);
        }
        s.clear();
        for(int i=n;i>=1;i--){
            while(s.size()&&a[s.back()]<a[i])s.pop_back();
            if(s.size())r[i]=s.back();
            s.push_back(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int len=a[i];
            if(i-l[i]<r[i]-i){
                for(int j=l[i]+1;j<=i;j++){
                    int k=j+len-1;
                    if(k>=i&&k<r[i])ans++;
                }
            }else{
                for(int k=i;k<=r[i]-1;k++){
                    int j=k-len+1;
                    if(j<=i&&j>l[i])ans++;
                }
            }
        }
        cout<<ans<<"\n";
    };
    int t;cin>>t;
    while(t--)solve();
    return 0;
}