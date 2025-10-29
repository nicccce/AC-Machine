// https://codeforces.com/gym/104128/problem/D

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, k, m, c, d;
        cin >> n >> k >> m >> c >> d;
        
        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];

        function<bool(int)> check = [&](int x){
            int cntOri = 0;
            vector<int> trans(n+5, 0), diff(n+5, 0);
            for(int i=1; i<=n; i++){
                if(a[i] >= x){
                    cntOri++;
                    trans[i] = 1e18;
                }
                else{
                    if(x-a[i] <= c) 
                        trans[i] = 1;
                    else if(d == 0)
                        trans[i] = 1e18;
                    else
                        trans[i] = 1 + (x-a[i]-c+d-1)/d;
                    // cout << trans[i] << " ";
                }
            }
            
            if(cntOri >= k)
                return 1;

            int add = 0;
            if(d==0 && c==0){
                return 0;
            }

            else{
                for(int i=1; i<=n; i++){
                    // 起始位置为j时等差数列能>=trans[i]的j的范围
                    int L = max(1LL, i+1-m);
                    int R = min(min(i, i+1-trans[i]), n-m+1);
                    if(L <= R){
                        diff[L]++;
                        diff[R+1]--;
                    }
                }
                
                for(int i=1; i<=n; i++){
                    diff[i] += diff[i-1];
                    add = max(add, diff[i]);
                }
            }

            // cout << "|" << cntOri << " " << add << "\n";

            if(cntOri+add >= k) return 1;
            else return 0;
        };

        int l=0, r=1e18, finalMax=0;
        while(l <= r){
            int mid = (l+r)>>1LL;
            if(check(mid)){
                finalMax = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }

        cout << finalMax << "\n";
    };

    solve();

    return 0;
}