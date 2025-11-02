// https://ac.nowcoder.com/acm/contest/32708/D

#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, cpyn;
        cin >> n;
        if(n == 0){
            cout << 7 << "\n";
            cout << "1 2 1 4 5 1 4\n";
            return;
        }
        if(n == 1){
            cout << 6 << "\n";
            cout << "1 1 4 5 1 4\n";
            return;
        }
        vector<int> bit;
        n--;
        while(n){
            bit.push_back(n&1);
            n >>= 1;
        }

        // int len = bit.size();
        vector<int> ans;
        int id = 0;
        int cnt1 = 0;
        for(int i=0; i<bit.size(); i++){
            if(bit[i] == 1){
                cnt1++;
                for(int j=0; j<i; j++){
                    ans.push_back(id+1);
                }   
                id++;
            }
        }

        // int tmp = id;
        for(int i=id; i<2*id; i++){
            ans.push_back(i+1);
        }
        cout << ans.size() << "\n";
        for(auto x: ans)
            cout << x << " ";
        cout << "\n";
    };

    solve();

    return 0;
}