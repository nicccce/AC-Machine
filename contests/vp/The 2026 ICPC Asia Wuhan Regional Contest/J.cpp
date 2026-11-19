#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        map<int,int> a;
        map<int,int,greater<int>> b;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            a[x]++;
        }
        for(int i=1,x;i<=n;i++){
            cin>>x;
            b[x]++;
        }
        using pii=pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> q1,q2;
        int s=0;
        for(auto [x,c]:b){
            if(a[x]>=c)q1.push({x-c,c});
            else q2.push({x-c,c});
            while(1){
                if(!q2.empty()&&q2.top().first<=s){
                    s+=q2.top().second;
                    q2.pop();
                }else if(!q1.empty()&&q1.top().first<=s){
                    s+=q1.top().second;
                    q1.pop();
                }else break;
            }
        }
        if(q2.empty()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}