// https://ac.nowcoder.com/acm/problem/253619
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto solve=[&](){
        int n;
        string s;
        cin>>n>>s;
        vector<int> q;
        for(int i=0;i<n;i++) 
            if(s[i]=='(')q.push_back(i);
        if(n%2 || q.size()!=n/2) {
            cout<<-1<<'\n';
            return;
        }
        int b=0,a=0,p=0;
        for(int i=0;i<n;i++){
            b+=(s[i]=='('?1:-1);
            if(b<0) {
                while(p<q.size() && q[p]<=i) p++;
                int j=q[p];
                a+=(j-i),b=1,p++;
                swap(s[i],s[j]);
            }
        }
        cout<<a<<'\n';
    };
    int t;
    for(cin>>t;t;t--) solve();
    return 0;
}