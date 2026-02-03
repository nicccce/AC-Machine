#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(3*n),b(3*n),vis(3*n,0);
        vector<pair<int,int>> ba,ab;
        vector<vector<int>> ans;
        for(int i=0;i<3*n;i++){
            cin>>a[i]>>b[i];
            ba.push_back({b[i],i});
            ab.push_back({a[i],i});
        }
        sort(ba.begin(),ba.end(),[&](pii x,pii y){
            if(x.first==y.first)return b[x.second]>b[y.second];
            return x.first<y.first; 
        });
        sort(ab.begin(),ab.end());
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int p=0;
        for(int i=0;i<3*n;i++){
            // cout<<ba[i].second<<endl;
            if(vis[ba[i].second])continue;
            while (p<3*n&&ab[p].first<=ba[i].first)
            {
                pq.push({b[ab[p].second],ab[p].second});
                p++;
            }
            vector<int> grp;
            grp.push_back(ba[i].second);
            vis[ba[i].second]=1;
            while (grp.size()<3&&!pq.empty())
            {
                pii x=pq.top();pq.pop();
                if(!vis[x.second]){
                    vis[x.second]=1;
                    grp.push_back(x.second);
                }
                // cout<<x.second<<'\n';
            }
            // cout<<grp.size()<<endl;
            if(grp.size()!=3){
                cout<<"No\n";
                return;
            }
            ans.push_back(grp);
        }
        cout<<"Yes\n";
        for(auto grp:ans){
            for(int i=0;i<3;i++)cout<<grp[i]+1<<" ";
            cout<<"\n";
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}