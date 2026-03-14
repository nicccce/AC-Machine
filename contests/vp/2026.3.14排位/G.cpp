// https://codeforces.com/problemset/problem/212/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> st(n+1);
        function<void(int,int)> dfsst=[&](int r,int f){
            st[r]=1;
            for(auto i:g[r]){
                if(i==f)continue;
                dfsst(i,r);
                st[r]+=st[i];
            }
        };
        dfsst(1,0);
        vector<bool> ans(n);
        function<void(int,int)> dfs=[&](int r,int f){
            vector<int> stset(n);
            for(auto i:g[r]){
                if(i==f)continue;
                dfs(i,r);
                stset[st[i]]++;
            }
            stset[st[1]-st[r]]++;
            set<int> dp;
            vector<int> sts;
            for(int i=1;i<n;i++){
                int base=1;
                // if(r==3){
                //     if(stset[i]>0){
                //         cout<<i;
                //         cout<<stset[i];
                //     }
                // }
                while(stset[i]>base){
                    sts.push_back(i*base);
                    stset[i]-=base;
                    base<<=1;
                }
                if(stset[i]!=0)sts.push_back(i*stset[i]);
            }
            dp.insert(0);
            for(auto i:sts){
                // if(r==4)cout<<i;
                set<int>tmp;
                for(auto j:dp){
                    tmp.insert(j+i);
                }
                for(auto j:tmp){
                    dp.insert(j);
                }
            }
            for(auto j:dp){
                ans[j]=1;
            }
        };
        dfs(1,0);
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(ans[i]){cnt++;
            }
        }
        cout<<cnt<<'\n';
        for(int i=1;i<n-1;i++){
            if(ans[i]){
                cout<<i<<' '<<n-1-i<<'\n';
            }
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}