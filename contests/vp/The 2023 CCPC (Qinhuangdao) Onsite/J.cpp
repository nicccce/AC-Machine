// https://codeforces.com/gym/104787/problem/J
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
int N=13;
    auto solve = [&](){
        int n,w;
        cin>>n>>w;
        vector<int> cnt(N);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            cnt[a-1]++;
        }
        vector<int> dp(1<<N);
        queue<int> q;
        q.push(0);
        while (1)
        {
            int now=q.front();
            q.pop();
            int cnt1=N;
            for(int i=0;i<N;i++){
                if(now&(1<<i)){
                    cnt1--;
                }
            }
            // cout<<now<<'\n';
            for(int i=1;i<(1<<cnt1);i++){
                int nt=now,pos=0,cost=0;
                for(int j=0;j<cnt1;j++){
                    while (now&(1<<pos))
                        pos++;
                    if(i&(1ll<<j)){
                        cost+=cnt[pos];
                        nt|=(1<<pos);
                    }
                    pos++;
                }
                if(cost<=w&&dp[nt]==0){
                    dp[nt]=dp[now]+1;
                    q.push(nt);
                    if(nt==(1<<N)-1){
                        cout<<dp[nt]<<'\n';
                        return;
                    }
                }
            }
        }
        
    };

    solve();

    return 0;
}