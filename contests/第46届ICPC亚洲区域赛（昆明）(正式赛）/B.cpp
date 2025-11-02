// https://ac.nowcoder.com/acm/contest/32708/B

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int mod = 998244353;

    auto qpow = [&](int a, int b, int mod){
        a %= mod;
        int res = 1LL;
        while (b){
            if (b & 1LL)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1LL;
        }
        return res % mod;
    };

    auto inverse = [&](int x){
        return qpow(x, mod - 2, mod);
    };

    auto solve = [&]{
        int n, w, h;
        cin >> n >> w >> h;
        vector<int> x1(n), x2(n), y1(n), y2(n); 
        for(int i=0; i<n; i++){
            cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        }
        vector<int> combx(2*n), comby(2*n);
        for(int i=0; i<n; i++){
            combx.push_back(x1[i]);
            combx.push_back(x2[i]);
            comby.push_back(y1[i]);
            comby.push_back(y2[i]);
        }

        combx.push_back(w);
        combx.push_back(h);

        sort(combx.begin(), combx.end());
        sort(comby.begin(), comby.end());
        combx.erase(unique(combx.begin(), combx.end()), combx.end());
        comby.erase(unique(comby.begin(), comby.end()), comby.end());

        int xmx=0,ymx=0;

        for(int i = 0; i < n; i++) {
            x1[i] = lower_bound(combx.begin(), combx.end(), x1[i]) - combx.begin();
            x2[i] = lower_bound(combx.begin(), combx.end(), x2[i]) - combx.begin();
            xmx=max({xmx,x1[i],x2[i]});
            y1[i] = lower_bound(comby.begin(), comby.end(), y1[i]) - comby.begin();
            y2[i] = lower_bound(comby.begin(), comby.end(), y2[i]) - comby.begin();
            ymx=max({ymx,y1[i],y2[i]});
        }

        w = lower_bound(combx.begin(), combx.end(), w) - combx.begin();
        xmx = max(xmx,w);

        h = lower_bound(comby.begin(), comby.end(), h) - comby.begin();
        ymx = max(ymx,h);

        xmx++; ymx++;

        vector<bool> is_des(1<<n,0);
        for(int i=0;i<(1<<n);i++){
            vector<vector<bool>> gg(xmx,vector<bool>(ymx,0)); 
            for(int b=0;b<n;b++){
                if((i&(1<<b))){
                    for(int x=x1[b];x<x2[b];x++){
                        for(int y=y1[b];y<y2[b];y++){
                            gg[x][y]=1;
                        }
                    }
                    
                }
            }
            is_des[i]=1;
            for(int x=0;x<w;x++){
                for(int y=0;y<h;y++){
                    if(gg[x][y]==0){
                        is_des[i]=0;
                    }        
                }
            }
        }
        if(is_des[(1<<n)-1]==0){
            cout<<"-1\n";
            return;
        }
        vector<int> dp(1<<n,-1);
        for(int i=(1<<n) - 1; i >= 0; i--){
            if(is_des[i]==1){
                dp[i]=0;
            }else{
                int cnt=n,k=0;
                for(int j=0;j<n;j++){
                    int tmp = (i|(1<<j));
                    if(tmp == i){
                        k++;
                    }else{
                        cnt = (cnt + dp[tmp]) % mod;
                    }
                }
                dp[i] = (cnt * inverse(n-k)) % mod;
            }
        }
        
        cout << dp[0] << '\n';
    };
    int t;
    for(cin>>t; t--;)
        solve();
    return 0;
}