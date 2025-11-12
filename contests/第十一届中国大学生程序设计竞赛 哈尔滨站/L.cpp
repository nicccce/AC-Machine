// https://qoj.ac/contest/2575/problem/14825

#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;

struct stat{
    int x, y, ud, dis;
};
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, 0};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m, k;
        cin >> n >> m >> k;
        // vector<PII> barr;
        map<int, int> barr, id;
        for(int i=1; i<=k; i++){
            int col, row;
            cin >> row >> col;
            barr[col] = row;
            id[col] = i;
        }

        vector<vector<vector<int>>> stp(n+1, vector<vector<int>>(m+1, vector<int>(1LL<<k, INT_MAX)));
        queue<stat> qe;

        for(int i=1; i<=n; i++){
            qe.push({i, 1, 0, 0});
            stp[i][1][0] = 0;
        }
        
        while(!qe.empty()){
            auto [x, y, ud, dis] = qe.front();
            qe.pop();

            for(int i=0; i<3; i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx<1 || xx>n || yy<1 || yy>m || barr[yy]==xx) continue;

                int nowUD = ud;

                if(barr[yy]!=0 && xx>barr[yy])
                    nowUD |= (1LL<<(id[yy]-1));

                if(stp[xx][yy][nowUD] == INT_MAX){
                    stp[xx][yy][nowUD] = dis+1;
                    qe.push({xx, yy, nowUD, dis+1});
                }
            }
        }

        for(int i=0; i<(1LL<<k); i++){
            int mi = INT_MAX;
            for(int j=1; j<=n; j++)
                mi = min(mi, stp[j][m][i]);
            if(mi == INT_MAX)
                cout << "-1 ";
            else
                cout << mi << " ";
        }
        cout << "\n";
    };

    int t;
    for(cin>>t; t--;)
        solve();

    return 0;
}