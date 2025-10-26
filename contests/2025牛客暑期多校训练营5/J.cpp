// https://ac.nowcoder.com/acm/contest/108302/J
#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mtr(n+1, vector<int>(m+1));
        vector<vector<int>> step(n+1, vector<int>(m+1, 1e9));

        queue<PII> qe;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> mtr[i][j];
                if(mtr[i][j] == 1){
                    qe.push({i, j});
                    step[i][j] = 0;
                }
            }
        }

        while(!qe.empty()){
            auto [nowx, nowy] = qe.front();
            qe.pop();
            for(int i=0; i<4; i++){
                int xx = nowx + dx[i];
                int yy = nowy + dy[i];
                if(xx>=1 && xx<=n && yy>=1 && yy<=m && step[xx][yy]==1e9){
                    if(step[nowx][nowy]+1 < step[xx][yy]){
                        step[xx][yy] = step[nowx][nowy]+1;
                        qe.push({xx, yy});
                    }
                }
            }
        }

//         for(int i=1; i<=n; i++)
//             for(int j=1; j<=m; j++)
//                 cout << step[i][j] << " ";

        function<bool(int)> check = [&](int stp){
            int mainMx=INT_MIN, mainMi=INT_MAX, subMx=INT_MIN, subMi=INT_MAX;
            int cnt = 0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(step[i][j] > stp){
                        cnt++;
                        mainMx = max(mainMx, i+j);
                        mainMi = min(mainMi, i+j);
                        subMx = max(subMx, i-j);
                        subMi = min(subMi, i-j);
                    }
                }
            }

            if(!cnt) 
                return 1;

            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                    if(i+j-stp<=mainMi && i+j+stp>=mainMx &&
                        i-j-stp<=subMi && i-j+stp>=subMx)
                            return 1;

            return 0; 
        };

        int l=0, r=n+m+1, finalMax=0;
        while(l <= r){
            int mid = ((l+r)>>1LL);
            if(check(mid)){
                finalMax = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        cout << finalMax << "\n";
    };

    solve();

    return 0;
}