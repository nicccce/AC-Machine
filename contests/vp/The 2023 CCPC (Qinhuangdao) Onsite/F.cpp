// https://codeforces.com/gym/104787/problem/F
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> pri;
bool not_prime[200005];

void Eular_Sleve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}

bool ispri(int i){
    return !not_prime[i];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    auto solve = [&](){
        Eular_Sleve(200001);
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<vector<int>> dp(n+1,vector<int>(4,0x3f3f3f3f));
        dp[1]={0,1,1,1};
        for(int i=2;i<=n;i++){
            if(a[i]%2)
                dp[i][0]=min(dp[i][0],dp[i-1][2]);
            else
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
            if(ispri(a[i]+a[i-1]))
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
            if(ispri(a[i]+1))
                dp[i][0]=min(dp[i][0],dp[i-1][3]);
            if(a[i-1]%2)
                dp[i][2]=min(dp[i][2],dp[i-1][0]+1),dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            else
                dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
            dp[i][1]=min(dp[i][1],dp[i-1][2]+1);
            dp[i][2]=min(dp[i][2],dp[i-1][1]+1);
            dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            dp[i][3]=min(dp[i][3],dp[i-1][3]+1);
            dp[i][3]=min(dp[i][3],dp[i-1][2]+1);
            if(ispri(a[i-1]+1))
                dp[i][3]=min(dp[i][3],dp[i-1][0]+1);
        }
        cout<<min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]})<<'\n';
    };

    solve();

    return 0;
}