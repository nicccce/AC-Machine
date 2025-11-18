// https://codeforces.com/contest/2144/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int> p(n+1);
        vector<int> present(n+1,0);
        vector<int> zeros;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            if(p[i]==0) zeros.pb(i);
            else present[p[i]]=1;
        }
        vector<int> missing;
        for(int v=1;v<=n;v++) if(!present[v]) missing.pb(v);
        int forced = -1;
        if((int)zeros.size()==1 && (int)missing.size()==1 && zeros[0]==missing[0]) forced = zeros[0];
        int first=-1, last=-1;
        for(int i=1;i<=n;i++){
            bool isMismatch=false;
            if(p[i]==0){
                if(i==forced) isMismatch=false;
                else isMismatch=true;
            } else {
                if(p[i]!=i) isMismatch=true;
            }
            if(isMismatch){
                if(first==-1) first=i;
                last=i;
            }
        }
        if(first==-1) cout<<0<<"\n";
        else cout<<(last-first+1)<<"\n";
    }
    return 0;
}
