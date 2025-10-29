// https://codeforces.com/gym/104128/problem/M
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
typedef pair<int,int> PII;
const int N=2e5,mod=998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,ans=0;
        cin>> n;
        vector<PII> g(n),gg(n);
        vector<int> flg(n);
        for(int i=0; i<n; i++){
            cin>>g[i].first>>g[i].second;
        }
        function<PII(PII,PII)> mi = [&](PII x,PII y){
            PII z= {-x.first+y.first, -x.second+y.second };
            return z;
        };
        function<int(PII,PII)> cross = [&](PII x,PII y){
            return x.first*y.second-x.second*y.first;
        };
        for(int i=0; i<n; i++){
            int k=(i+2)%n;
            while (g[k].second==g[(i+1)%n].second)k=(k+1)%n;
            if(mi(g[i],g[(i+1)%n]).second<0&&mi(g[(i+1)%n],g[k]).second>0){
                if(mi(g[(i+1)%n],g[(i+2)%n]).second==0){
                    ans+=(mi(g[(i+1)%n],g[(i+2)%n]).first>0);
                }else{
                    ans+=(cross(mi(g[i],g[(i+1)%n]),mi(g[(i+1)%n],g[k]))>0);
                }
            }
        
        }
        cout<<ans<<'\n';
    };
    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}